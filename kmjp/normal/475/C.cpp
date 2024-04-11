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
string S[2001];
int sx,sy;

int SS[2002][2002];

int okok(int sy,int sx,int h,int w) {
    int a=SS[sy+h][sx+w]-SS[sy+h][sx]-SS[sy][sx+w]+SS[sy][sx];
    return a==w*h;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>H>>W;
    FOR(y,H) cin>>S[y];
    sx=sy=-1;
    FOR(y,H) FOR(x,W) if(sy==-1 && S[y][x]=='X') sy=y,sx=x;
    FOR(y,H) FOR(x,W) if(S[y][x]=='X' && (y<sy || x<sx)) return _P("-1\n");
    FOR(y,H) {
        FOR(x,W) SS[y+1][x+1]=SS[y+1][x]+(S[y][x]=='X');
        FOR(x,W) SS[y+1][x+1]+=SS[y][x+1];
    }
    int mi=1<<30;
    int w,h;
    for(h=1;h<=H;h++) for(w=1;w<=W;w++) if(okok(sy,sx,h,w) && h*w<mi) {
        int ng=0;
        int tp=w*h;
        x=sx,y=sy;
        while(1) {
            int mr=0,md=0;
            if(x+w<W && S[y][x+w]=='X') mr=1;
            if(y+h<H && S[y+h][x]=='X') md=1;
            if(mr==md) break;
            if(mr) {
                tp+=h;
                x++;
            }
            else {
                tp+=w;
                y++;
            }
        }
        
        if(tp==SS[H][W]) mi=h*w;
    }
    
    
    if(mi==1<<30) _P("-1\n");
    else _P("%d\n",mi);
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}