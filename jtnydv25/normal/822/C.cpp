#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(n) scanf("%d", &(n))
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
vector<int> pos[N];
vector<int> prefix[N];
vector<pair<int, pair<int, int> > > vec;
int main(){
    int n, x, l, r, c;
    sd(n); sd(x);
    for(int i = 1; i <= n; i++){
        sd(l); sd(r); sd(c);
        vec.pb({l, {r, c}});
    }
    sort(vec.begin(), vec.end());
    const int INF = 2e9 + 10;
    int ans = INF;
    for(int i = 0; i < vec.size(); i++){
        l = vec[i].F, r = vec[i].S.F, c = vec[i].S.S;
        int d = r - l + 1;
        int d1 = x - d;
        if(d1 >= 1){
            int ind = upper_bound(pos[d1].begin(), pos[d1].end(), l - 1) - pos[d1].begin();
            ind--;
            if(ind >= 0) ans = min(ans, c + prefix[d1][ind]);
        }
        pos[r - l + 1].pb(r);
        if(prefix[d].empty()){
            prefix[d].push_back(c);
        }
        else prefix[d].push_back(min(prefix[d].back(), c));
    }
    if(ans == INF) ans = -1;
    cout << ans;
}