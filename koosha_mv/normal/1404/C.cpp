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
 
const int N=3e6+99;

int n,T,a[N],Fen[N],p[N],ans[N];
pair<int,int> q[N];
vector<int> qu[N];

void update(int x,int val){ x++;  while(x<=N)  {  Fen[x]+=val;  x+=(x&-x);  } }
int query(int x){ x++; int res=0;  while(x>0)  {  res+=Fen[x];  x-=(x&-x);  } return res; } 

int main(){
    cin>>n>>T;
    f(i,1,n+1){ gett(a[i]); a[i]=i-a[i]; }
    f(i,1,n+1){
        if(a[i]<0) p[i]=0;
        else{
            int l=0,r=i+1,mid;
            while(l+1<r){
                mid=(l+r)/2;
                if(a[i]<=(i-1)-query(mid-1)) l=mid;
                else r=mid;
            }
            p[i]=l;
        }
        update(p[i],1);
    }
    f(i,0,T){
        Gett(q[i].F,q[i].S);
        q[i].S=n-q[i].S;
        qu[q[i].S].pb(i);
    }
    f(i,1,N) Fen[i]=0;
    f(i,1,n+1){
        update(p[i],1);
        f(j,0,qu[i].size())
            ans[qu[i][j]]=query(q[qu[i][j]].F);
    }
    f(i,0,T)
        cout<<q[i].S-ans[i]<<" ";
}