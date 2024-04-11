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

int H,W,K;
char LR[1001][1001];
char UD[1001][1001];
int res[1001][1001];

void solve() {
    int i,j,k,l,r,x,y,sw=0; string s;
    
    cin>>H>>W>>K;
    FOR(y,H) {
        FOR(x,W-1) cin>>LR[y][x], LR[y][x]=LR[y][x]=='N';
        if(y<H-1) FOR(x,W) cin>>UD[y][x], UD[y][x]=UD[y][x]=='N';
    }
    
    if(K==1) {
        int ret=0;
        FOR(y,H) FOR(x,W-1) ret+=LR[y][x];
        FOR(y,H-1) FOR(x,W) ret+=UD[y][x];
        if(ret*4>H*(W-1)+(H-1)*W) return _P("NO\n");
        _P("YES\n");
        FOR(y,H) FOR(x,W) _P("1%s",x==W-1?"\n":" ");
        return;
    }
    
    
    if(W<H) {
        FOR(x,W) {
            for(y=1;y<H;y++) res[y][x]=res[y-1][x]^UD[y-1][x];
            if(x>0) {
                int wo=0;
                FOR(y,H) wo+=res[y][x]^res[y][x-1]^LR[y][x-1];
                if(wo>H/2) FOR(y,H) res[y][x]^=1;
            }
        }
    }
    else {
        FOR(y,H) {
            for(x=1;x<W;x++) res[y][x]=res[y][x-1]^LR[y][x-1];
            if(y>0) {
                int wo=0;
                FOR(x,W) wo+=res[y][x]^res[y-1][x]^UD[y-1][x];
                if(wo>W/2) FOR(x,W) res[y][x]^=1;
            }
        }
    }
    _P("YES\n");
    FOR(y,H) FOR(x,W) _P("%d%s",res[y][x]+1,x==W-1?"\n":" ");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}