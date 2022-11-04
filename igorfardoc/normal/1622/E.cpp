#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vi x(n);
        for(int i = 0; i < n; i++) {
            cin >> x[i];
        }
        vector<string> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll ans = -10000;
        vi pmax;
        for(int mask = 0; mask < (1 << n); mask++) {
            vvi am(21);
            for(int i = 0; i < m; i++) {
                int here = 0;
                for(int j = 0; j < n; j++) {
                    if(((mask >> j) & 1) ^ ((int)(a[j][i] - '0'))) {
                        ++here;
                    } else {
                        --here;
                    }
                }
                am[here + 10].push_back(i);
            }
            vi p(m);
            int now = m;
            for(int i = 20; i >= 0; i--) {
                for(const auto& el : am[i]) {
                    p[el] = now--;
                }
            }
            ll anshere = 0;
            for(int i = 0; i < n; i++) {
                ll sum = 0;
                for(int j = 0; j < m; j++) {
                    if(a[i][j] == '1') {
                        sum += p[j];
                    }
                }
                if((mask >> i) & 1) {
                    anshere += x[i];
                    anshere -= sum;
                } else {
                    anshere -= x[i];
                    anshere += sum;
                }
            }
            if(anshere > ans) {
                ans = anshere;
                pmax = p;
            }
        }
        for(const auto& el : pmax) {
            cout << el << ' ';
        }
        cout << '\n';
    }

}