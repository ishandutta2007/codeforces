#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include <iomanip>
#include <clocale>
#include <bitset>
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

#define int long long
#define data NE_data
#define rank NE_rank
#define time NE_time
#define endl '\n'


int MOD = 998244353;

int pow(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2 == 0) {
        return pow((a * a) % MOD, b / 2);
    } else {
        return (pow(a, b - 1) * a) % MOD;
    }
}

int fact[1000000];
int obr_fact[1000000];

void init() {
    fact[0] = 1;
    for (int i = 1; i < 200000; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    for (int i = 0; i < 200000; i++) {
        obr_fact[i] = pow(fact[i], MOD - 2);
    }
}

int c(int k, int n) {
    int ans = fact[n];
    ans *= obr_fact[k];
    ans %= MOD;
    ans *= obr_fact[n - k];
    ans %= MOD;
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    int n;
    cin >> n;
    vector<string> arr(n);

    int bal1 = 0;
    int bal2 = 0;

    int cnt1 = 0;
    int cnt2 = 0;


    int cnt3 = 0;

    bool was = false;
    bool can1 = false;
    bool can2 = false;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i][1] == 'B') {
            arr[i][1] = 'W';
        } else {
            if (arr[i][1] == 'W') {
                arr[i][1] = 'B';
            }
        }

        if (arr[i] == "WB" || arr[i] == "BW") {
            was = true;
        }

        if (arr[i][0] != 'W' && arr[i][1] != 'W') {
            can1 = true;
        }
        if (arr[i][0] != 'B' && arr[i][1] != 'B') {
            can2 = true;
        }


        if (arr[i][0] == 'B') {
            bal1++;
        }
        if (arr[i][0] == 'W') {
            bal2++;
        }

        if (arr[i][1] == 'B') {
            bal1--;
        }
        if (arr[i][1] == 'W') {
            bal2--;
        }

        if (arr[i][0] == '?') {
            cnt1++;
        }
        if (arr[i][1] == '?') {
            cnt2++;
        }


        if (arr[i] == "??") {
            cnt3++;
        }
    }


    if (bal1 + bal2 + cnt1 != cnt2) {
        cout << 0;
        return 0;
    }
    //cout << bal1 << " " << bal2 << " " << cnt1 << " " << cnt2 << endl;

    int ans = 0;

    for (int i = 0; i <= cnt1; i++) {


        int now_bal1 = bal1 + i;
        int now_bal2 = bal2 + cnt1 - i;

        int now = c(i, cnt1);

        if (now_bal1 + now_bal2 != cnt2) {
            continue;
        }

        if (now_bal1 < 0 || now_bal2 < 0) {
            continue;
        }


        now *= c(now_bal1, cnt2);
        now %= MOD;
        ans += now;
        ans %= MOD;
    }

    if (!was && can1 && can2) {
        int lol = 1;
        for (int i = 0; i < cnt3; i++) {
            lol *= 2;
            lol %= MOD;
        }
        ans -= lol;

        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (arr[i][0] == 'B' || arr[i][1] == 'B') {
                flag = true;
            }
        }

        if (!flag) {
            ans++;
        }

        flag = false;
        for (int i = 0; i < n; i++) {
            if (arr[i][0] == 'W' || arr[i][1] == 'W') {
                flag = true;
            }
        }

        if (!flag) {
            ans++;
        }

        ans += MOD;
        ans %= MOD;
    }
    cout << ans;

}