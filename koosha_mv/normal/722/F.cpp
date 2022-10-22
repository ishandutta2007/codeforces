#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define is_bit(x,y) (0<(x&(1ll<<y)))
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define Add(x,y) x=(x+y)%mod;
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first
 
const int N=1e5+99,K=41;

int n,m,bad,rem[K][K],t[K];
vector<pair<int,pair<int,int> > >v[N];
vector<int> d[N];

void add(pair<int,pair<int,int> > x){
    f(i,0,d[x.S.F].size()){
        int dv=d[x.S.F][i],re=x.S.S%dv;
        rem[dv][re]++;
        if(rem[dv][re]==1){
            t[dv]++;
            if(t[dv]==2) bad++;
        } 
    }
}
void del(pair<int,pair<int,int> > x){
    f(i,0,d[x.S.F].size()){
        int dv=d[x.S.F][i],re=x.S.S%dv;
        rem[dv][re]--;
        if(rem[dv][re]==0){
            t[dv]--;
            if(t[dv]==1) bad--;
        } 
    }
}

int main(){
    f(i,2,K)
        for(int j=i;j<K;j+=i)
            d[j].pb(i);
    cin>>n>>m;
    f(i,0,n){
        int ki;
        gett(ki);
        f(j,0,ki){
            int x;
            gett(x);
            v[x].pb(mp(i,mp(ki,j)));
        }
    }
    f(i,1,m+1){
        f(j,0,K) f(l,0,K) rem[j][l]=t[j]=bad=0;
        int l=0,ans=0;
        f(r,0,sz(v[i])){
            add(v[i][r]);
            while(l<r && (bad || v[i][r-1].F+1<v[i][r].F)){
                del(v[i][l]);
                l++;
            }
            maxm(ans,r-l+1);
        }
        cout<<ans<<" ";
    }
}