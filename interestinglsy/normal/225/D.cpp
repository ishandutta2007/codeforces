#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <ctime>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define calm (l+r)>>1
const int INF=2139062143;

const int maxn=20;
int n,m,maxlen;
ll base;
char pic[maxn][maxn];
bool vis[15][15][65536];
int go[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int rev[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct snake{
    int x,y;
    int status;
    snake():x(0),y(0),status(0){}
}start;
inline bool judge(int x,int y){
    return x>=0&&x<n&&y>=0&&y<m;
}
void startpos(){//
    maxlen=0;
    int x,y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)if(pic[i][j]!='#'&&pic[i][j]!='@'){
            if(pic[i][j]-'0'>maxlen){
                x=i;y=j;
                maxlen=pic[i][j]-'0';
            }
            if(pic[i][j]=='1'){
                start.x=i;start.y=j;
            }
        }
    }
    base=(1<<((maxlen-1)*2))-1;//1
    int &status=start.status;
    status=0;
    while(pic[x][y]!='1'){
        for(int i=0;i<4;i++){
            int xx=x+rev[i][0],yy=y+rev[i][1];
            if(judge(xx,yy)&&pic[xx][yy]==pic[x][y]-1){
                status<<=2;
                status|=i;
                x=xx;y=yy;
                break;
            }
        }
    }
}
#define F first
#define S second
bool bomb(int xx,int yy,snake s){//
    int &status=s.status;
    int x=s.x,y=s.y;
    if(x==xx&&y==yy)return false;
    for(int i=1;i<maxlen-1;i++){
        x+=go[status&3][0];
        y+=go[status&3][1];
        status>>=2;
        if(x==xx&&y==yy)return false;
    }
    return true;
}
int BFS(){
    queue<pair<snake,int> > Q;
    Q.push(mp(start,0));
    vis[start.x][start.y][start.status]=true;
    while(!Q.empty()){
        snake st=Q.front().F;
        int step=Q.front().S;
        if(pic[st.x][st.y]=='@')return step;
        Q.pop();
        for(int i=0;i<4;i++){
            int xx=st.x+rev[i][0];
            int yy=st.y+rev[i][1];
            if(judge(xx,yy)&&pic[xx][yy]!='#'&&bomb(xx,yy,st)){
                snake next;
                next.x=xx;next.y=yy;
                next.status=((st.status<<2)&base)|i;
                if(!vis[xx][yy][next.status]){
                    vis[xx][yy][next.status]=true;
                    Q.push(mp(next,step+1));
                }
            }
        }
    }
    return -1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%s",pic[i]);
    }
    startpos();
    printf("%d\n",BFS());
    return 0;
}