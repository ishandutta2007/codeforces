#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("f.inp","r",stdin)
#define OUTPUT freopen("f.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e5+10;

int n,m,G[N][26],G1[N][26],h[26]={0};
string s1,s2;
int main(){
    cin>>n>>m>>s1>>s2;
    FOR(i,1,n)
        FOR(j,0,25) G[i][j]=(G[i-1][j]*2+(s1[i-1]-'a'==j))%MOD;
    FOR(i,1,m)
        FOR(j,0,25) G1[i][j]=(G1[i-1][j]*2+(s2[i-1]-'a'==j))%MOD;
    int p2=1;
    FOR(i,1,m) p2=p2*2%MOD;
    FOR(i,1,m) h[s2[i-1]-'a']=i;
    //cout<<p2<<'\n';
    vector <int> ans;
    FOR(i,m,n){
        bool ok=true;
        //printf("%d\n",i);
        FOR(j,0,25) if (h[j]){
            int pos=h[j];
            int x=s1[i-m+pos-1]-'a';
            if ((G[i][x]-(1LL*G[i-m][x]*p2)%MOD+MOD)%MOD!=G1[m][j]) ok=false;
            if (x!=j&&(G[i][j]-(1LL*G[i-m][j]*p2)%MOD+MOD)%MOD!=G1[m][x]) ok=false;
            //printf("%d %d %lld %d\n",i,j,(G[i][x]-(1LL*G[i-m][x]*p2)%MOD+MOD)%MOD,G1[m][j]);
        }
        if (ok) ans.push_back(i-m+1);
    }
    printf("%d\n",ans.size());
    for(auto i:ans) printf("%d ",i);
}