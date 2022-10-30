#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()

vector<vector<int> > A;
const int N = 5e5+7;
const int INF = 1e9+7;
int vis[N];
vector<vector<int> > pref[2],suf[2];
// 0 - min,1 - max
void solve(){
    A.clear();
    for(int c = 0;c<2;++c)
        pref[c].clear(),suf[c].clear();
    int n,m;
    cin>>n>>m;
    A.resize(n);
    for(int i = 0;i<n;++i)
        A[i].resize(m);
    for(int c = 0;c<2;++c)
        pref[c].resize(n),suf[c].resize(n);
    for(int i = 0;i<n;++i) {
        for (int j = 0; j < m; ++j)
            cin >> A[i][j];
        for(int c = 0;c<2;++c)
            pref[c][i].resize(m),suf[c][i].resize(m);
        for(int j = 0;j<m;++j){
            pref[0][i][j] = INF;
            pref[1][i][j] = -INF;
            if (j>0)
                pref[0][i][j] = pref[0][i][j-1],pref[1][i][j] = pref[1][i][j-1];
            pref[0][i][j] = min(pref[0][i][j],A[i][j]);
            pref[1][i][j] = max(pref[1][i][j],A[i][j]);
        }
        for(int j = m-1;j>=0;--j){
            suf[0][i][j] = INF;
            suf[1][i][j] = -INF;
            if (j+1<m)
                suf[0][i][j] = suf[0][i][j+1],suf[1][i][j] = suf[1][i][j+1];
            suf[0][i][j] = min(suf[0][i][j],A[i][j]);
            suf[1][i][j] = max(suf[1][i][j],A[i][j]);
        }
    }
    for(int sep = 0;sep+1<m;++sep){
        set<pair<int,int> > smi1,smx1,smi2,smx2;
        for(int i = 0;i<n;++i){
            smx1.insert({pref[1][i][sep],i});
            smi2.insert({suf[0][i][sep+1],i});
        }
        while(smx1.size()>1){
            int move = smx1.rbegin()->second;
            smx1.erase({pref[1][move][sep],move});
            smi1.insert({pref[0][move][sep],move});
            smi2.erase({suf[0][move][sep+1],move});
            smx2.insert({suf[1][move][sep+1],move});
            if (smx1.rbegin()->first<smi1.begin()->first && smx2.rbegin()->first<smi2.begin()->first){
                cout<<"YES\n";
                for(int i = 0;i<n;++i)
                    vis[i] = 0;
                for(auto [val,pos]:smx1)
                    vis[pos] = 1;
                for(int i = 0;i<n;++i)
                    cout<<(vis[i]==0?'R':'B');
                cout<<' '<<sep+1<<endl;
                return;
            }
        }
    }
    cout<<"NO\n";
}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;

    while(t--)
        solve();
}