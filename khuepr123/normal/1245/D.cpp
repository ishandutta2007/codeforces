#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, a[maxN], x, y;
pair<int, int> pr[maxN];
int ans;
int c[maxN];
int k[maxN];
int par[maxN];
vector<pair<int, pair<int, int>>> vc;
int  find(int i){ return (par[i] = (par[i] - i) ? find(par[i]) : i);}
void unite(int i, int j) {
    if(c[find(i)] > c[find(j)]) swap(i, j);
    par[find(j)] = find(i);
}
bool sameset(int i, int j) {return (find(i) == find(j));}

signed main(){
    ios_base::sync_with_stdio(0);
    cin >> n;
    ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> pr[i].fi >> pr[i].se;
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        par[i] = i;
        ans += c[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> k[i];
    }
    vector<pair<int, int>> gap;
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            vc.pb(make_pair( (k[i] + k[j]) * 
            (abs(pr[i].fi - pr[j].fi) + abs(pr[i].se - pr[j].se)),
            make_pair(i, j)));
        }
    }
    sort(vc.begin(), vc.end());
    for(int i = 0; i < vc.size(); i++){
        if(sameset(vc[i].se.se, vc[i].se.fi)) continue;
        x = find(vc[i].se.se); // 3
        y = find(vc[i].se.fi); // 5
        if(c[x] > c[y]) swap(x, y);
        if(vc[i].fi < c[y]){
            ans = ans - c[y] + vc[i].fi;
            unite(y, x);
            gap.pb(make_pair(vc[i].se.fi, vc[i].se.se));
        }
        
    }
    cout << ans << endl;
    vector<int> an;
    for(int i = 1; i <= n; i++){
        if(par[i] == i) an.pb(i);
    }
    cout << an.size() << endl;
    for(int i = 0; i < an.size(); i++) cout << an[i] << ' ';
    cout << endl << gap.size() << endl;
    for(int i = 0; i < gap.size(); i++) cout << gap[i].fi << ' ' << gap[i].se << "\n";
}