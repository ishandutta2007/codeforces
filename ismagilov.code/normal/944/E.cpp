#include <bits/stdc++.h>
#define fs first
#define sc second
#define mp make_pair
#define vc vector
#define pr pair
#define pb push_back
#define ld long double
#define all(v) v.begin(), v.end()
#define len(v) (int)v.size()
#define endl "\n"
#define in cin
#define out cout

using namespace std;

main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    in >> n >> m;
    vc<int> me(m + 3, 0);
    for (int i = 0; i < n; i++){
        int l, r;
        in >> l >> r;
        me[l - 1]++;
        me[r]--;
    }
    int tkans = 0;
    int a[m];
    for (int i = 0; i < m; i++){
        tkans += me[i];
        a[i] = tkans;
    }
    int maxi[m];
    int maxi1[m];
    {
        vc<int> d(m + 1, 1000000000);
        d[0] = -1;
        for (int i = 0; i < m; i++){
            int l = 0;
            int r = m + 1;
            while (r - l > 1){
                int mid = (l + r) / 2;
                if (d[mid] > a[i]){
                    r = mid;
                }
                else{
                    l = mid;
                }
            }
            maxi[i] = l;
            d[l + 1] = min(d[l + 1], a[i]);
        }
    }
    {
        vc<int> d(m + 1, 1000000000);
        d[0] = -1;
        for (int i = m - 1; i >= 0; i--){
            int l = 0;
            int r = m + 1;
            while (r - l > 1){
                int mid = (l + r) / 2;
                if (d[mid] > a[i]){
                    r = mid;
                }
                else{
                    l = mid;
                }
            }
            maxi1[i] = l;
            d[l + 1] = min(d[l + 1], a[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++){
        ans = max(ans, maxi[i] + maxi1[i] + 1);
    }
    out << ans;
}