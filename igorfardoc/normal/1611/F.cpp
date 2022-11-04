#include<bits/stdc++.h>
#define LOG 19
#define MAX 300000
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vi p;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    p.resize(MAX);
    p[1] = 0;
    for(int i = 2; i < MAX; i++) {
        p[i] = p[i / 2] + 1;
    }
    int t;
    cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s;
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> suff(n + 1, 0);
        for(int i = n - 1; i >= 0; i--) {
            suff[i] = suff[i + 1] + a[i];
        }
        vector<vector<ll>> table(n + 1, vector<ll>(LOG));
        for(int st = 0; (1 << st) <= n + 1; st++) {
            for(int i = 0; i + (1 << st) <= n + 1; i++) {
                if(st == 0) {
                    table[i][st] = suff[i];
                    continue;
                }
                table[i][st] = max(table[i][st - 1], table[i + (1 << (st - 1))][st - 1]);
            }
        }
        int l1 = -1;
        int r1 = -2;
        for(int i = 0; i < n; i++) {
            int l = 0;
            int r = n - i + 1;
            while(r - l > 1) {
                int mid = (l + r) / 2;
                int end = i + mid - 1;
                int len1 = mid + 1;
                ll maxcan = suff[i] + s;
                ll max1 = max(table[i][p[len1]], table[i + len1 - (1 << p[len1])][p[len1]]);
                if(max1 > maxcan) {
                    r = mid;
                } else {
                    l = mid;
                }
            }
            if(l > r1 - l1 + 1) {
                l1 = i;
                r1 = i + l - 1;
            }
        }
        if(l1 == -1) {
            cout << "-1\n";
            continue;
        }
        cout << l1 + 1 << ' ' << r1 + 1 << '\n';
    }
}