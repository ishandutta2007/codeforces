#include<bits/stdc++.h>
using namespace std;
class Solver{
private:
    static constexpr int MAX_N=5e4+5;
    int q,n,m;
    int cntr[MAX_N],cntc[MAX_N];
    string g[MAX_N];
public:
    void solve(){
        int q;
        cin>>q;
        while(q--){
            cin>>n>>m;
            for(int i=1;i<=m;++i){
                cntc[i]=0;
            }
            for(int i=1;i<=n;++i){
                cin>>g[i];
                cntr[i]=0;
                for(int j=1;j<=m;++j){
                    if(g[i][j-1]=='*'){
                        ++cntr[i];
                        ++cntc[j];
                    }
                }
            }
            int ans=0;
            for(int i=1;i<=n;++i){
                for(int j=1;j<=m;++j){
                    ans=max(ans,cntr[i]+cntc[j]-(g[i][j-1]=='*'));
                }
            }
            cout<<n+m-1-ans<<endl;
        }
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Solver().solve();
    return 0;
}