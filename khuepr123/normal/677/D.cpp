/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
*/
// lethal option

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define eb emplace_back
#define ii pair<int, int>
#define iii pair<int, ii>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const int mod = 1e9 + 7;
const int maxN = 300005;
int n;
int x, y, z, k, m;

vector<ii> chs[maxN];
int ds[305][305];
queue<ii> q;
vector<iii> stall;

int xx[] = {-1, 0, 1, 0};
int yy[] = {0, -1, 0, 1};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for1(i, 1, n) for1(j, 1, m){
        cin >> x;
        chs[x].pb(ii(i, j));
    }
    for1(i, 0, 304) for1(j, 0, 304) ds[i][j] = -mod;
    chs[0].pb(ii(1, 1));
    ds[1][1] = 0;
    for1(pn, 0, k - 1){
        if(chs[pn].size() <= 300){
            for(ii cl : chs[pn + 1]){
                x = cl.fi; y = cl.se; z = mod;
                for(ii cl2 : chs[pn]){
                    z = min(z, ds[cl2.fi][cl2.se] + abs(x - cl2.fi) + abs(y - cl2.se));
                }
                ds[x][y] = z;
            }
        }
        else{
            stall.clear();
            for(ii cc : chs[pn]) stall.pb({ds[cc.fi][cc.se], cc});
            sort(stall.begin(), stall.end(), greater<iii>());
            for1(i, 1, n) for1(j, 1, m) ds[i][j] = mod;
            for(auto fol : stall) ds[fol.se.fi][fol.se.se] = fol.fi;
            while(!(q.empty() && stall.empty())){
                if(q.empty()) q.push(stall.back().se);
                auto &fal = q.front();
                int vl = ds[fal.fi][fal.se];
                while(!stall.empty()){
                    auto &fol = stall.back();
                    if(vl == fol.fi){
                        q.push(fol.se); stall.pop_back();
                    }
                    else break;
                }
                ii pr = q.front(); q.pop();
                x = pr.fi; y = pr.se;
                int df = ds[x][y] + 1;
                for1(id, 0, 3){
                    int vx = x + xx[id];
                    int vy = y + yy[id];
                    if(ds[vx][vy] > df){
                        ds[vx][vy] = df;
                        q.push(ii(vx, vy));
                    }
                }
            }
        }
    }
    ii pore = chs[k][0];
    cout << ds[pore.fi][pore.se] << endl;
}