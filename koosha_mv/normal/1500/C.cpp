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
 
const int N=1505;
 
int n,m,cp,a[N][N],b[N][N],ind[N],num[N],cnt[N],Mask[N];
bool mask[N][N],mv[N][N],res[N];
vector<int> v[N],ans;
map<vector<int>,vector<int> > mark;
 
void output(){
    cout<<ans.size()<<endl;
    f_(i,ans.size()-1,0)
        cout<<ans[i]+1<<" ";
    exit(0);
}
int main(){
    cin>>n>>m;
    f(i,0,n)
        f(j,0,m)
            gett(a[i][j]);
    f(i,0,n){
        vector<int> v;
        f(j,0,m){    
            gett(b[i][j]);
            v.pb(b[i][j]);
        }  
        mark[v].pb(i);
    }
    f_(i,n-1,0){
        vector<int> v;
        f(j,0,m)  
            v.pb(a[i][j]);
        if(mark[v].size()==0) return cout<<-1,0;
        ind[i]=mark[v][mark[v].size()-1];
        num[ind[i]]=i;
        mark[v].pop_back();
    }
    f(i,0,n-1){
        if(num[i]<num[i+1])
            mask[m][i]=1;
        else
            mv[m][i]=1,cnt[m]++,v[i].pb(m);
    }
    f(j,0,m){
        f(i,0,n)
            num[ind[i]]=a[i][j];
        f(i,0,n-1){
            if(num[i]<num[i+1])
                mask[j][i]=1;
            if(num[i+1]<num[i])
                mv[j][i]=1,cnt[j]++,v[i].pb(j);
        }
    }
    cp=n;
    n=m+1;
    m=cp-1;
    queue<int>q;
    f(i,0,n)
        if(cnt[i]==0)
            q.push(i);
    while(q.size()){
        int u=q.front();
        q.pop();
        if(u==n-1) output();
        ans.pb(u);
        f(i,0,m)
            if(Mask[i]==0 && mask[u][i]==1){
                Mask[i]=1;
                f(j,0,v[i].size())
                    if(--cnt[v[i][j]]==0)
                        q.push(v[i][j]);
            }
    }
    cout<<-1;
}