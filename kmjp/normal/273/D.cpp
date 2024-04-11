#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll dp[2][160][160][2][2];
ll S[160][160][2][2];
ll mo=1000000007;
int N,M;

ll diff(int x1,int x2,int y1,int y2,int ii,int jj) {
    ll ret=S[x2+1][y2+1][ii][jj]-S[x1][y2+1][ii][jj]-S[x2+1][y1][ii][jj]+S[x1][y1][ii][jj];
    return ((ret%mo)+mo)%mo;
}

void solve() {
    int i,j,k,l,r,x,y,x2,y2,h;
    
    cin>>N>>M;
    FOR(x,M) for(y=x;y<M;y++) dp[1][x][y][0][0]=1;
    
    ll ret=0;
    for(h=1;h<=N;h++) {
        ll tmp=0;
        int cur=h%2,tar=cur^1;
        FOR(x,M) for(y=x;y<M;y++) tmp+=dp[cur][x][y][0][0]+dp[cur][x][y][0][1]+dp[cur][x][y][1][0]+dp[cur][x][y][1][1];
        ret+=tmp%mo*(N+1-h);
        
        ZERO(S);
        ZERO(dp[tar]);
        FOR(i,2) FOR(j,2) {
            FOR(x,M) {
                FOR(y,M) S[x+1][y+1][i][j]=(S[x+1][y][i][j]+dp[cur][x][y][i][j])%mo;
                FOR(y,M) S[x+1][y+1][i][j]=(S[x+1][y+1][i][j]+S[x][y+1][i][j])%mo;
            }
        }
        
        FOR(x,M) for(y=x;y<M;y++) {
            ll(&to)[2][2]=dp[tar][x][y];
            to[0][0]+=diff(x,y,x,y,0,0);
            to[0][1]+=diff(x,y,y+1,M-1,0,0);
            to[1][0]+=diff(0,x-1,x,y,0,0);
            to[1][1]+=diff(0,x-1,y+1,M-1,0,0);
            
            to[0][1]+=diff(x,y,y,M-1,0,1);
            to[1][1]+=diff(0,x-1,y,M-1,0,1);
            
            to[1][0]+=diff(0,x,x,y,1,0);
            to[1][1]+=diff(0,x,y+1,M-1,1,0);
            
            to[1][1]+=diff(0,x,y,M-1,1,1);
            /*
            FOR(x2,M) for(y2=x2;y2<M;y2++) {
                ll(&from)[2][2]=dp[cur][x2][y2];
                if(x2<x &&y2<y && x<=y2) to[1][0]+=from[0][0]+from[1][0];
                if(x2<x &&y2==y) to[1][0]+=from[0][0]+from[1][0], to[1][1]+=from[0][1]+from[1][1];
                if(x2<x &&y2>y ) to[1][1]+=from[0][0]+from[1][0]+from[0][1]+from[1][1];
                if(x2==x&&y2<y ) to[0][0]+=from[0][0], to[1][0]+=from[1][0];
                if(x2==x&&y2==y) to[0][0]+=from[0][0],to[0][1]+=from[0][1],to[1][0]+=from[1][0],to[1][1]+=from[1][1];
                if(x2==x&&y2>y ) to[0][1]+=from[0][0]+from[0][1],to[1][1]+=from[1][0]+from[1][1];
                if(x2>x &&y2<y ) to[0][0]+=from[0][0];
                if(x2>x &&y2==y) to[0][0]+=from[0][0],to[0][1]+=from[0][1];
                if(x2>x &&y2>y && y>=x2) to[0][1]+=from[0][0]+from[0][1];
            }
            */
            to[0][0]%=mo;
            to[0][1]%=mo;
            to[1][0]%=mo;
            to[1][1]%=mo;
        }
    }
    cout << ret%mo << endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}