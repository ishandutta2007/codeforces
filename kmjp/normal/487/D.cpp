#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,Q;
string S[100020];
int toto[100020][11][2];
const int SP=300;

void rebuild(int v) {
    int x,y;
    for(y=v*SP;y<min((v+1)*SP,N);y++) {
        FOR(x,M) if(S[y][x]=='^') {
            if(y%SP==0) toto[y][x][0]=y-1, toto[y][x][1]=x;
            else toto[y][x][0]=toto[y-1][x][0], toto[y][x][1]=toto[y-1][x][1];
        }
        FOR(x,M) if(S[y][x]=='<') {
            if(x==0) toto[y][x][0]=y, toto[y][x][1]=-1;
            else if(S[y][x-1]=='>') toto[y][x][0]=toto[y][x][1]=-2;
            else toto[y][x][0]=toto[y][x-1][0], toto[y][x][1]=toto[y][x-1][1];
        }
        for(x=M-1;x>=0;x--) if(S[y][x]=='>') {
            if(x==M-1) toto[y][x][0]=y, toto[y][x][1]=M;
            else if(S[y][x+1]=='<') toto[y][x][0]=toto[y][x][1]=-2;
            else toto[y][x][0]=toto[y][x+1][0], toto[y][x][1]=toto[y][x+1][1];
        }
    }
    
}

void solve() {
    int i,j,k,l,r,x,y; string s; char c;
    
    cin>>N>>M>>Q;
    FOR(i,N) cin>>S[i];
    FOR(i,(N+SP-1)/SP) rebuild(i);
    
    while(Q--) {
        cin>>s>>y>>x;
        x--,y--;
        if(s[0]=='A') {
            while(0<=y && y<N && 0<=x && x<M) i=toto[y][x][0],x=toto[y][x][1],y=i;
            _P("%d %d\n",y+1,x+1);
        }
        else {
            cin>>c;
            S[y][x]=c;
            rebuild((y)/SP);
        }
    }
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}