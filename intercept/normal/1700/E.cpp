#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
const int M=4e5+9;
int n,m;
vector<int>a[M];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int t=0;
bool in(int x,int y){
    return x>=1&&y>=1&&x<=n&&y<=m;
}
bool pd(int x,int y){
    if(a[x][y]==1)return 1;
    for(int i=0;i<4;++i){
        int fx=x+dx[i],fy=y+dy[i];
        if(in(fx,fy)&&a[fx][fy]<a[x][y])return 1;
    }
    return 0;
}
int ans=0;
bool pd2(int x,int y){
    if(!pd(x,y))return 0;
    for(int i=0;i<4;++i){
        int fx=x+dx[i],fy=y+dy[i];
        if(in(fx,fy)&&!pd(fx,fy))return 0;
    }
    return 1;
}
vector<pii>p;
void sol(int x,int y,int tx,int ty){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(i==tx&&j==ty)continue;
            swap(a[x][y],a[i][j]);
            bool flag=pd2(x,y)&&pd2(i,j);
            for(auto o:p){
                flag&=pd2(o.fi,o.se);
            }
            ans+=flag;
            swap(a[x][y],a[i][j]);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        a[i].resize(m+1);
        for(int j=1;j<=m;++j){
            scanf("%d",&a[i][j]);
        }
    }
    int t=0,x,y;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(!pd(i,j))t++,x=i,y=j,p.eb(i,j);
        }
    }
    if(!t)puts("0");
    else if(p.size()>4)puts("2");
    else{
        sol(x,y,0,0);
        for(int i=0;i<4;++i){
            int fx=x+dx[i],fy=y+dy[i];
            if(in(fx,fy))sol(fx,fy,x,y);
        }
        if(ans)printf("1 %d\n",ans);
        else puts("2");
    }
    return 0;
}
/*
3
0 1 0
1 1 0
1 0 1
0 0 1
*/