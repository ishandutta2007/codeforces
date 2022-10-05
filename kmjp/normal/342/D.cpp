#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
void _fill_ll(ll* p,ll val,int rep) {int i; FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define MINUSL(a) _fill_ll((ll*)a,-1LL,sizeof(a)/8)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N;
string S[4];
char S2[4][10002];
ll mo=1000000007;

int pt(int x,int y) {
    if(x<0 || x>=N || y<0 || y>=3) return 1;
    if(S2[y][x]=='X') return 1;
    S2[y][x]='X';
    return 0;
}

ll dodo() {
    ll dp[10002][8];
    int x,y,ma,cm,nm;
    ZERO(dp);
    dp[0][0]=1;
    FOR(x,N) {
        cm=(S2[0][x]=='X')*4+(S2[1][x]=='X')*2+(S2[2][x]=='X');
        nm=(x==N-1)?7:((S2[0][x+1]=='X')*4+(S2[1][x+1]=='X')*2+(S2[2][x+1]=='X'));
        
        FOR(ma,8) {
            if((ma & cm) != cm) continue;
            int pm=ma^cm;
            //_P("[%d:%d:%d:%d:%lld]",x,ma,pm,nm,dp[x][pm]);
            if(ma==0) {
                dp[x+1][7]+=dp[x][pm]; // -- -- --
                dp[x+1][4]+=dp[x][pm]; // | --
                dp[x+1][1]+=dp[x][pm]; // -- |
            }
            else if(ma==1) {
                dp[x+1][6]+=dp[x][pm]; // -- --
                dp[x+1][0]+=dp[x][pm]; // |
            }
            else if(ma==2) dp[x+1][5]+=dp[x][pm]; // -- --
            else if(ma==4) {
                dp[x+1][3]+=dp[x][pm]; // -- --
                dp[x+1][0]+=dp[x][pm]; // |
            }
            else if(ma==3) dp[x+1][4]+=dp[x][pm];
            else if(ma==5) dp[x+1][2]+=dp[x][pm];
            else if(ma==6) dp[x+1][1]+=dp[x][pm];
            else if(ma==7) dp[x+1][0]+=dp[x][pm];
        }
        FOR(ma,8) dp[x+1][ma] %= mo;
        //FOR(ma,8) _P("%lld ",dp[x+1][ma]);
        //_P("\n");
    }
    
    return dp[N][0];
}

void solve() {
    int f,i,j,k,l, x,y;
    int sx,sy;
    
    cin>>N;
    FOR(i,3) cin>>S[i];
    FOR(y,3) FOR(x,N) if(S[y][x]=='O') S[y][x]='X', sy=y, sx=x;
    
    ll ret=0;
    FOR(i,4*4*4*4) {
        int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
        int LM=i%4, RM=(i/4)%4;
        int TM=(i/16)%4,BM=(i/64)%4;
        if(LM!=0 && RM!=1 && TM!=2 && BM!=3) continue;
        if(sx==0 && LM!=0) continue;
        if(sx==N-1 && RM!=0) continue;
        if(sy==0 && TM!=0) continue;
        if(sy==2 && BM!=0) continue;
        
        
        FOR(j,3) strcpy(S2[j],S[j].c_str());
        int ng=0;
        if(sx>0) ng+=pt(sx-1,sy),ng+=pt(sx-1+dx[LM],sy+dy[LM]);
        if(sx<N-1) ng+=pt(sx+1,sy),ng+=pt(sx+1+dx[RM],sy+dy[RM]);
        if(sy>0) ng+=pt(sx,sy-1),ng+=pt(sx+dx[TM],sy-1+dy[TM]);
        if(sy<2) ng+=pt(sx,sy+1),ng+=pt(sx+dx[BM],sy+1+dy[BM]);
        if(ng) continue;
        
        //_P("%s\n%s\n%s\n",S2[0].c_str(),S2[1].c_str(),S2[2].c_str());
        ret=(ret + dodo()) % mo;
        //_P("%d %lld\n",i,ret);
    }
    _P("%d\n",ret);
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}