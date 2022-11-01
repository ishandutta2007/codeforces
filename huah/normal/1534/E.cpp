#include<bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
#define inf 0x3f3f3f3f
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define nep(i,r,l) for(int i=r;i>=l;i--)
void sc(int &x){scanf("%d",&x);}
void sc(int &x,int &y){scanf("%d%d",&x,&y);}
void sc(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void sc(ll &x){scanf("%lld",&x);}
void sc(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void sc(ll &x,ll &y,ll &z){scanf("%lld%lld%lld",&x,&y,&z);}
void sc(char *x){scanf("%s",x);}
void sc(char *x,char *y){scanf("%s%s",x,y);}
void sc(char *x,char *y,char *z){scanf("%s%s%s",x,y,z);}
void out(int x){printf("%d\n",x);}
void out(ll x){printf("%lld\n",x);}
void out(int x,int y){printf("%d %d\n",x,y);}
void out(ll x,ll y){printf("%lld %lld\n",x,y);}
void out(int x,int y,int z){printf("%d %d %d\n",x,y,z);}
void out(ll x,ll y,ll z){printf("%lld %lld %lld\n",x,y,z);}
using namespace std;
const int N=505,mod=1e9+7;
int n,k;
vector<int>v;
int a[N]={0,35727201,36804049,21455440,15073837,17926126,8049691,56674323};
bool test;
int Q()
{
    printf("?");
    for(int x:v) printf(" %d",x);
    putchar('\n');
    if(test)
    {
        int res=0;
        for(int x:v) res^=a[x];
        return res;
    }
    fflush(stdout);
    int ans;scanf("%d",&ans);
    return ans;
}
void print(int ans)
{
    printf("! %d\n",ans);
    fflush(stdout);
}
int dp[N][N];
pair<int,int>pre[N][N];
pair<int,int>op[N][N];
queue<pair<int,int>>q;
int main()
{
    srand(time(0));
    //freopen("1.in","r",stdin);freopen("1.out","w",stdout);
    //test=true;
    if(test)
    {
        n=rand()%20+1;k=rand()%n+1;
        //n=8;k=3;
        //cout<<n<<' '<<k<<endl;
        rep(i,1,n) a[i]=rand()*rand()%100000000+1;
        //rep(i,1,n) printf(i==n?"%d\n":"%d ",a[i]);
        int ans=0;
        rep(i,1,n) ans^=a[i];
        printf("Ans: %d\n",ans);
    }
    else sc(n,k);
    dp[0][n]=1;
    q.push({0,n});
    while(!q.empty())
    {
        int x=q.front().first,y=q.front().second;q.pop();
        for(int i=0;i<=x&&i<=k;i++)
            if(k-i<=y)
        {
            int xx=x-i+(k-i);
            int yy=y-(k-i)+i;
            if(!dp[xx][yy])
            {
                dp[xx][yy]=dp[x][y]+1;
                pre[xx][yy]={x,y};
                op[xx][yy]={i,k-i};
                q.push({xx,yy});
            }
        }
    }
    if(!dp[n][0])
    {
        out(-1);
        fflush(stdout);
        return 0;
    }
    stack<pair<int,int>>s;
    int x=n,y=0;
    while(!(x==0&&y==n))
    {
        s.push(op[x][y]);
        pair<int,int>z=pre[x][y];
        x=z.first;y=z.second;
    }
    vector<int>v1,v2;
    rep(i,1,n) v2.push_back(i);
    int ans=0;
    while(!s.empty())
    {
        pair<int,int>x=s.top();s.pop();
        int a=x.first,b=x.second;
        vector<int>v3,v4;
        v.clear();
        while(a--)
        {
            v.push_back(v1.back());
            v3.push_back(v1.back());
            v1.pop_back();
        }
        while(b--)
        {
            v.push_back(v2.back());
            v4.push_back(v2.back());
            v2.pop_back();
        }
        ans^=Q();
        for(int x:v3) v2.push_back(x);
        for(int x:v4) v1.push_back(x);
    }
    printf("! %d\n",ans);
    fflush(stdout);
}