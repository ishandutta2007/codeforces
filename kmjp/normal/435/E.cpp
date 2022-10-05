#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
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
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int H,W;
char S[1001][1001];
char S2[1001][1001];

void dor() { // same 2 row
    int y,x,j;
    
    FOR(y,2) {
        FOR(x,W) if(S[y][x]!=S2[y][x%2]&&S[y][x]!='0') return;
        FOR(x,W) S2[y][x]=S2[y][x%2];
    }
    for(y=2;y<H;y++) {
        int ng=0;
        FOR(x,W) if(S[y][x]!='0') {
            if(S[y][x]!=S2[y%2][x%2]) ng|=1;
            if(S[y][x]!=S2[y%2][(x%2)^1]) ng|=2;
        }
        if(ng==3) return;
        j=(ng==1);
        FOR(x,W) S2[y][x]=S2[y%2][(x%2)^j];
    }
    FOR(y,H) _P("%s\n",S2[y]);
    exit(0);
}

void doc() { // same 2 col
    int y,x,j;
    
    FOR(x,2) {
        FOR(y,H) if(S[y][x]!=S2[y%2][x]&&S[y][x]!='0') return;
        FOR(y,H) S2[y][x]=S2[y%2][x];
    }
    for(x=2;x<W;x++) {
        int ng=0;
        FOR(y,H) if(S[y][x]!='0') {
            if(S[y][x]!=S2[y%2][x%2]) ng|=1;
            if(S[y][x]!=S2[(y%2)^1][x%2]) ng|=2;
        }
        if(ng==3) return;
        j=(ng==1);
        FOR(y,H) S2[y][x]=S2[(y%2)^j][x%2];
    }
    FOR(y,H) _P("%s\n",S2[y]);
    exit(0);
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>H>>W;
    FOR(y,H) cin>>S[y];
    char C[5]="1234";
    
    do {
        S2[0][0]=C[0];
        S2[0][1]=C[1];
        S2[1][0]=C[2];
        S2[1][1]=C[3];
        dor();
        doc();
    } while(next_permutation(C,C+4));
    
    _P("0\n");
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}