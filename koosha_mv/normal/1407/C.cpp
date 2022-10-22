#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e4+9;

int n,mv,mark[N],ans[N];

int main(){
    cin>>n;
    vector<int> V(n);
    f(i,0,n) V[i]=i+1;
    while(1<V.size()){
        int u,v,x,y;
        u=V[sz(V)-1];
        v=V[sz(V)-2];
        V.pop_back();
        V.pop_back();
        cout<<"? "<<u<<" "<<v<<endl;
        cin>>x;
        cout<<"? "<<v<<" "<<u<<endl;
        cin>>y;
        if(y<x){
            ans[u]=x;
            mark[x]=1;
            V.pb(v);
        }
        else{
            ans[v]=y;
            mark[y]=1;
            V.pb(u);
        }
    }
    f(i,1,n+1)
        if(!mark[i])
            mv=i;
    cout<<"! ";
    f(i,1,n+1)
        cout<<(ans[i] ? ans[i] : mv)<<" ";
}