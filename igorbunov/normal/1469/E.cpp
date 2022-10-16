#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
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

#define s second
#define f first
#define push_back emplace_back
#define endl "\n"
#define int long long

mt19937 rnd(5757);
int Bpow[1100000];
int B = rnd() % 1000 + 23;
int P = 1e9 + 179;


void fill() {
    Bpow[0] = 1;
    for (int i = 1; i < 1100000; i++) {
        Bpow[i] = (Bpow[i - 1] * B) % P;
    }
}

vector <int> h(vector<int> &b) {
    int hash = 0;
    vector<int> ans;
    ans.push_back(hash);
    for (int i = 0; i < b.size(); i++) {
        hash = (ans.back() * B + (int)(b[i] + 1)) % P;
        ans.push_back(hash);
    }
    return ans;
}

int h_on_interval(int l, int r, vector<int> &hash) {
    return (hash[r] - hash[l] * Bpow[r - l] + P * P) % P;
}

int n, k;

unordered_set<int> kek;

vector<int> now;
vector<int> ans;
bool flag = false;
void gen(int ind, int now_hash) {
    if (flag) {
        return;
    }
    if (ind == k) {
        for (int i = 0; i < now.size(); i++) {
            //cout << now[i] << " ";
        }
        //cout << endl;
        //cout << now_hash << endl << endl;
        if (kek.find(now_hash) == kek.end()) {
            ans = now;
            flag = true;
        }
        return;
    }
    now.push_back(0);
    gen(ind + 1, (now_hash * B + 1) % P);
    now.pop_back();
    if (flag) {
        return;
    }
    now.push_back(1);
    gen(ind + 1, (now_hash * B + 2) % P);
    now.pop_back();
}
void solve() {
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> arr(n);
    flag = false;
    ans.clear();
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            arr[i] = 1;
        } else {
            arr[i] = 0;
        }
    } 
    auto hash = h(arr);
    kek.clear();
    for (int i = 0; i < n - k + 1; i++) {
        //cout << h_on_interval(i, i + k, hash) << endl;
        kek.insert(h_on_interval(i, i + k, hash));
    }
    //cout << "GEN START\n";
    gen(0, 0);
    if (ans.size() != 0) {
        cout << "YES\n";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fill();
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}