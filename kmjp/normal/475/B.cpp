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

int H,W;
string LR,UD;
int vis[2][20][20];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>H>>W;
    cin>>LR;
    cin>>UD;
    
    if(LR[0]=='<' && UD[0]=='v' && LR[H-1]=='>' && UD[W-1]=='^') return _P("YES\n");
    if(LR[0]=='>' && UD[0]=='^' && LR[H-1]=='<' && UD[W-1]=='v') return _P("YES\n");
    return _P("NO\n");
    
    queue<int> Q;
    vis[0][0][0]=vis[1][0][0]=1;
    Q.push(0);
    Q.push(1000);
    while(Q.size()) {
        int dir=Q.front()/1000;
        int cy=Q.front()%1000/20;
        int cx=Q.front()%20;
        Q.pop();
        
        if((LR[cy]=='<') ^ dir) {
            FOR(x,cx) if(vis[dir][cy][x]==0) {
                vis[dir][cy][x]=1;
                Q.push(dir*1000+cy*20+x);
            }
        }
        else {
            for(x=cx+1;x<W;x++) if(vis[dir][cy][x]==0) {
                vis[dir][cy][x]=1;
                Q.push(dir*1000+cy*20+x);
            }
        }
        
        if((UD[cx]=='^') ^ dir) {
            FOR(y,cy) if(vis[dir][y][cx]==0) {
                vis[dir][y][cx]=1;
                Q.push(dir*1000+y*20+cx);
            }
        }
        else {
            for(y=cy+1;y<H;y++) if(vis[dir][y][cx]==0) {
                vis[dir][y][cx]=1;
                Q.push(dir*1000+y*20+cx);
            }
        }
    }
    
    int ng=0;
    FOR(y,H) FOR(x,W) ng+=(vis[0][y][x]==0)+(vis[1][y][x]==0);
    if(ng) _P("NO\n");
    else _P("YES\n");
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}