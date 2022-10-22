#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
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

const int N=255,C=4,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int n,m,x,y,u,v,o,p,mxr[N],mxc[N],mark[N*N],a[N][N],ans[N][N];
queue<pair<int,int> > q;

void check(int x,int y){
    int res=0;
    if(x<1 || n<x || y<1 || m<y || ans[x][y]) return ;
    f(i,0,C)
        res+=(ans[x+dx[i]][y+dy[i]]>0);
    if(1<res){
        q.push(mp(x,y));
    }
}
void Set(int x,int y,int s){
    ans[x][y]=s;
    f(i,0,C)
        check(x+dx[i],y+dy[i]);
}
void print(){
    f(i,1,n+1){
        f(j,1,m+1){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    cin>>n>>m;
    f(i,1,n+1)
        f(j,1,m+1){
            int x;
            cin>>x;
            maxm(mxr[i],x);
            maxm(mxc[j],x);
        }
    x=n,y=m;
    f(i,1,m+1)
        mark[mxc[i]]=2;
    f(i,1,n+1)
        mark[mxr[i]]+=1;
    u=n+1,v=m+1;
    f(i,1,n*m+1)
        if(mark[i]==3)
            u--,v--;
    o=u,p=v;
    x=u-1,y=v-1;
    f_(i,n*m,1){
        if(mark[i]){
            if(mark[i]&1 && mark[i]>1)
                Set(u,v,i),u++,v++;
            else{
                if(mark[i]&1) Set(x,p,i),x--;
                else Set(o,y,i),y--;
            }
        }
        else{
            if(q.size()==0) return 0;
            pair<int,int> p=q.front();
            q.pop();
            Set(p.F,p.S,i);
        }
     //   print();
    }
    print();
}