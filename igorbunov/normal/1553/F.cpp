#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>

using namespace std;

#define endl '\n'
#define int long long


const int SZ = 2500000;
long long t1[SZ];

void incr1(int i, int delta) {
    for (int I = i; I <= SZ; I += (I & -I)) {
        t1[I] += delta;
    }
}

int sum11(int i) {
    int ans = 0;
    for (int I = i; I > 0; I -= (I & -I)) {
        ans += t1[I];
    }
    return ans;
}

long long t3[SZ];

void incr3(int i, int delta) {
    for (int I = i; I <= SZ; I += (I & -I)) {
        t3[I] += delta;
    }
}

int sum33(int i) {
    int ans = 0;
    for (int I = i; I > 0; I -= (I & -I)) {
        ans += t3[I];
    }
    return ans;
}

int mas[SZ];
long long t2[SZ];

void push(int v, int vl, int vr) {
    int vm = (vl + vr) / 2;
    if (v * 2 + 1 < SZ) {
        mas[v * 2 + 1] += mas[v];
    }
    if (v * 2 + 1 < SZ) {
        mas[v * 2 + 2] += mas[v];
    }
    t2[v] += (long long)(vr - vl) * mas[v];
    mas[v] = 0;
}

long long all_sum2(int v, int l, int r, int vl, int vr) {
    push(v, vl, vr);
    if (l >= r) {
        return 0;
    }
    if (l == vl && r == vr) {
        return t2[v];
    }
    int vm = (vl + vr) / 2;
    long long sum1 = all_sum2(v * 2 + 1, l, min(r, vm), vl, vm);
    long long sum2 = all_sum2(v * 2 + 2, max(l, vm), r, vm, vr);
    return sum1 + sum2;
}

void update2(int v, int l, int r, int vl, int vr, int val) {
    push(v, vl, vr);
    if (l >= r) {
        return;
    }
    if (l == vl && r == vr) {
        mas[v] += val;
        push(v, vl, vr);
        return;
    }
    int vm = (vl + vr) / 2;
    update2(v * 2 + 1, l, min(r, vm), vl, vm, val);
    update2(v * 2 + 2, max(l, vm), r, vm, vr, val);
    t2[v] = t2[v * 2 + 1] + t2[v * 2 + 2];
}

int MAX_VAL = 300001;


int tt1[400000];
int tt3[400000];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    //n = 300000;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        //arr[i] = i + 1;
    }
    long long ans1 = 0;
    long long ans2 = 0;
    for (int i = 0; i < n; i++) {
        //all del to us
        int now = arr[i];
        int kek = 0;

        for (int j = 0; j < MAX_VAL; j += now) {
            long long val1 = sum11(min(j + now, MAX_VAL)) - sum11(j);
            long long val2 = sum33(min(j + now, MAX_VAL)) - sum33(j);
            ans1 += val1 - val2 * kek;
            kek += now;
        }

        //us del to all
        ans2 += all_sum2(0, 0, now + 1, 0, MAX_VAL);
        for (int j = 0; j < MAX_VAL; j += now) {
            update2(0, j + 1, min(j + now, MAX_VAL), 0, MAX_VAL, 1);
            update2(0, j + now, min(j + now + 1, MAX_VAL), 0, MAX_VAL, -(now - 1));
        }
        incr1(now + 1, now);
        incr3(now + 1, 1);
        //update1(0, 0, MAX_VAL, now, now);
        //update3(0, 0, MAX_VAL, now, 1);
        tt1[now] = now;
        tt3[now] = 1;
        cout << ans1 + ans2 << endl;
    }
    //cout << ans1 + ans2;
}