#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, m; int a[maxN];
ii b[maxN];
int x, y, z, k;
int cnt[maxN];
vector<int> vc[maxN];
vector<int> spr;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> m;
        for(int i = 1; i <= n * m; i++){
            cin >> a[i];
            b[i].fi = a[i];
            b[i].se = i;
        }
        spr.clear();
        sort(b + 1, b + (m * n) + 1);
        for(int i = 1; i <= m; i++){
            vc[i].clear();
            cnt[i] = 0;
        }
        for(int i = 1; i <= m; i++){
            cnt[(b[i].se - 1) % m + 1]++;
            vc[(b[i].se - 1) % m + 1].pb(b[i].se);
        }
        for(int i = 1; i <= m; i++){
            cnt[i]--;
            if(cnt[i] > 0){
                while(1){
                    spr.pb(vc[i].back());
                    vc[i].pop_back();
                    cnt[i]--;
                    if(cnt[i] == 0) break;
                }
            }
        }
        for(int i = 1; i <= m; i++){
            if(cnt[i] < 0){
                int hh = spr.back();
                spr.pop_back();
                swap(a[hh], a[(((hh - 1) / m) * m) + i]);
            }
        }
        for(int i = 1; i <= n * m; i++){
            cout << a[i] << " ";
            if(i % m == 0) cout << endl;
        }
    }
}