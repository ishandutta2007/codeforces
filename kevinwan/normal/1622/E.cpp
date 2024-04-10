#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mn=10010;
const ll mod = 998244353;

ll a[mn];
int sgn[mn],w[mn];
string s[mn];
int bes=0;
int p[mn],o[mn],ro[mn];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>s[i];
    iota(o,o+m,0);
    bes=INT_MIN;
    for(int msk=0;msk<1<<n;msk++){
        int cand=0;
        for(int i=0;i<n;i++){
            sgn[i]=1-(msk>>i)%2;
            cand+=(sgn[i]?-a[i]:a[i]);
        }
        for(int i=0;i<m;i++)w[i]=0;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++){
            w[j]+=(sgn[i]?1:-1)*(s[i][j]-'0');
        }
        sort(o,o+m,[](int i,int j){
            return w[i]<w[j];
        });
        for(int i=0;i<m;i++)cand+=(i+1)*w[o[i]];
        if(cand>bes){
            bes=cand;
            memcpy(p,o,sizeof(o[0])*m);
        }
    }
    cerr<<bes<<endl;
    for(int i=0;i<m;i++)ro[p[i]]=i;
    for(int i=0;i<m;i++)printf("%d ",ro[i]+1);
    printf("\n");
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);

    int tc;
    cin>>tc;
    while(tc--){
        solve();
    }
}