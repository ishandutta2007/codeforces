#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define SF scanf
#define PF printf
#define MAXN 2010
#define INF 0x3f3f3f3f
using namespace std;
int n,s;
int dp[MAXN],com[MAXN],cnt;
vector<int> las[MAXN],now;
pair<int,int> a[MAXN];
int len(int x,int y){
    if(x>y)
        swap(x,y);
    return min(y-x,x+n-y);
}
int len(int x,int y,int blo){
    if(x>y)
        swap(x,y);
    if(blo==x||blo==y)
        return len(x,y);
    if(x<blo&&blo<y)
        return x+n-y;
    if(blo<x||blo>y)
        return y-x;
}
bool checkin(int x,int l,int r){
    if(l<r)
        return x>=l&&x<=r;
    else
        return x<=r||x>=l;
}
void solve(){
    int m=now.size();
    for(int i=0;i<m;i++)
        for(int j=0;j<las[cnt].size();j++){
            int prep=now[(i-1+m)%m];
            int lasp=now[(i+1+m)%m];
            int u=now[i];
            int v=las[cnt][j];
            int val=0;
            if(prep==lasp){
                val=len(v,prep)+len(prep,u);
                //PF("[1]");
            }
            else if(checkin(v,prep,lasp)){
                val=n-len(u,v,prep);
                //PF("[2]");
            }
            else
                val=len(v,prep,u)+len(v,lasp,u)+min(len(v,lasp,u)+len(prep,u),len(v,prep,u)+len(lasp,u));
            //PF("{%d %d}\n",u,val);
            if(cnt!=0)
                val+=dp[las[cnt][j]];
            if(val<dp[now[i]]){
                dp[now[i]]=val;
                com[now[i]]=j;  
            }
        }
    cnt++;
    for(int i=0;i<m;i++)
        las[cnt].push_back(now[i]);
    now.clear();
}
vector<int> print;
int len1(int x,int y){
    //PF("{%d %d}\n",x,y);
    int lenx=len(x,y);
    if((x+lenx-1)%n+1==y)
        return lenx;
    else
        return -lenx;
}
void get_ans(int x,int tim){
    if(tim!=1)
        get_ans(com[las[tim][x]],tim-1);
    int m=las[tim].size();
    int prep=las[tim][(x-1+m)%m];
    int lasp=las[tim][(x+1)%m];
    int u=las[tim][x];
    int v=las[tim-1][com[u]];
    int val=0;
    if(prep==lasp){
        print.push_back(len1(v,prep));
        if(prep!=u)
            print.push_back(len1(prep,u));
    }
    else if(checkin(v,prep,lasp)){
        if(checkin(v,prep,u)){
            print.push_back(len1(v,prep));
            for(int j=(x-1+m)%m;j!=x;j=(j-1+m)%m)
                print.push_back(len1(las[tim][j],las[tim][(j-1+m)%m]));
        }
        else{
            print.push_back(len1(v,lasp));
            for(int j=(x+1)%m;j!=x;j=(j+1)%m)
                print.push_back(len1(las[tim][j],las[tim][(j+1)%m]));
        }
    }
    else{
        if(len(v,lasp,u)+len(prep,u)<len(v,prep,u)+len(lasp,u)){
            print.push_back(len1(v,lasp));
            for(int j=(x+1)%m;j!=x;j=(j+1)%m)
                print.push_back(len1(las[tim][j],las[tim][(j+1)%m]));
        }
        else{
            print.push_back(len1(v,prep));
            for(int j=(x-1+m)%m;j!=x;j=(j-1+m)%m)
                print.push_back(len1(las[tim][j],las[tim][(j-1+m)%m]));
        }
    }
    //PF("{%d %d %d}\n",u,tim,print.size());
}
int main(){
    memset(dp,INF,sizeof dp);
    SF("%d%d",&n,&s);
    for(int i=1;i<=n;i++){
        SF("%d",&a[i].first);
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    las[0].push_back(s);
    now.push_back(a[1].second);
    for(int i=2;i<=n;i++){
        if(a[i].first!=a[i-1].first){
            solve();
        }
        now.push_back(a[i].second);
    }
    solve();
    /*for(int i=0;i<=cnt;i++){
        for(int j=0;j<las[i].size();j++)
            PF("{%d %d} ",las[i][j],dp[las[i][j]]);
        PF("\n");
    }*/
    int minid=0,minv=INF;
    for(int i=0;i<las[cnt].size();i++)
        if(dp[las[cnt][i]]<minv){
            minid=i;
            minv=dp[las[cnt][minid]];   
        }
    PF("%d\n",minv);
    get_ans(minid,cnt);
    for(int i=0;i<print.size();i++){
        if(print[i]>=0)
            PF("+%d\n",print[i]);
        else
            PF("%d\n",print[i]);
    }
}