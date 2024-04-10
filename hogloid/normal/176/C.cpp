#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int xdif,ydif;
int glued[10][10];
bool rec(int x1,int y1,int x2,int y2,int turn){
    if(mp(x1,y1)==mp(x2,y2)){
        return false;
    }
    if(turn==0){
        bool res=false;
        if(glued[y1][x1]==0) for(int i=0;i<2;++i){
            int px=x1+dx[i],py=y1+dy[i];
            if(px<0 || py<0 || px>xdif || py>ydif) continue;
            if(rec(px,py,x2,y2,1)==false){
                res=true;
                break;
            }
        }
        if(!res && glued[y2][x2]==0) for(int i=2;i<4;++i){
            int px=x2+dx[i],py=y2+dy[i];
            if(px<0 || py<0 || px>xdif || py>ydif) continue;
            if(rec(x1,y1,px,py,1)==false){
                res=true;
                break;
            }
        }
        return res;
    }else{
        bool res=false;
        REP(i,ydif+1) REP(j,xdif+1) if(!glued[i][j] &&
            mp(i,j)!=mp(y1,x1) && mp(i,j)!=mp(y2,x2)){
            glued[i][j]=1;
            bool val=rec(x1,y1,x2,y2,0);
            glued[i][j]=0;
            if(val==false){
                res=true;
                break;
            }
        }
        return res;
    }
}

bool solve(){
    int x1,y1,x2,y2;
    scanf("%*d%*d%d%d%d%d",&x1,&y1,&x2,&y2);
    xdif=abs(x1-x2);ydif=abs(y1-y2);
    if(xdif>ydif) swap(xdif,ydif);
    if(xdif>4 || ydif>4) return true;
    if(xdif==4 && ydif==4) return true;
    if(xdif==3 && ydif==4) return true;
    
    return false;
}
int main(){
    if(solve()) puts("Second");
    else puts("First");
    return 0;
}