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
 
const int N=1e5+99,sq=317;
 
int n,k,T,l=1,r,rt,ch[N],rs[N],in[N],type[N];
unordered_map<ll,int> mark;
pair<int,int> q[N];
ll ans,a[N],res[N];
 
void go(int L,int R){
    while(l<L){
        mark[a[l]]--;
        ans-=mark[a[l]+k];
        l++;
    }
    while(L<l){
        l--;
        ans+=mark[a[l]+k];
        mark[a[l]]++;
    }
    while(r<R){
        r++;
        ans+=mark[a[r]-k];
        mark[a[r]]++;
    }
    while(R<r){
        if(rt){
        mark[a[r]]--;
        ans-=mark[a[r]-k];
        r--;
        }
    }
        
}
int main(){
    cin>>n>>k;
    rt=1;
    f(i,1,n+1) gett(type[i]);
    f(i,1,n+1){
        gett(a[i]);
        if(type[i]==1) a[i]+=a[i-1];
        else a[i]=a[i-1]-a[i];
    }
    cin >> T;
    f(i,0,T){
        Gett(ch[i],rs[i]);
        ch[i]--;
    }
    iota(in,in+T,0);
    sort(in,in+T, [](int i, int j){
            return ch[i] / sq == ch[j] / sq ? (ch[i] / sq) & 1 ? rs[i] < rs[j] : rs[i] > rs[j] : ch[i] < ch[j];
        });
    f(i,0,T){
        int x=in[i];
        go(ch[x],rs[x]);
        res[x]=ans;
       // eror(x);
    }
    print(res,T);
}