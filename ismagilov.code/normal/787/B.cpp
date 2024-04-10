#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"
#define endd "\n"; return 0;

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < m; i++){
        int k;
        cin >> k;
        map<int, int> g;
        bool prav = 0;
        for (int i1 = 0; i1 < k; i1++){
            int a;
            cin >> a;
            if (g[-a] != 0){
                prav = 1;
            }
            g[a]++;
        }
        ans += prav;
    }
    if (ans < m){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}