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
string S[401];
int num[405][405][2];


void solve() {
    int f,i,j,k,l,x,y,x2,y2;
    
    cin>>H>>W;
    FOR(y,H) cin>>S[y];
    FOR(y,H) FOR(x,W) S[y][x]=S[y][x]=='0';
    
    FOR(y,H) {
        FOR(x,W) num[y+1][x+1][0]=S[y][x]?(1+num[y+1][x][0]):0;//L
        FOR(x,W) num[y+1][x+1][1]=S[y][x]?(1+num[y][x+1][1]):0;//U
    }
    
    ll ret=0;
    FOR(y,H) FOR(x,W) if(S[y][x]) {
        //UR,R
        for(l=1;x+l<W && y-l>=0 && S[y-l][x+l] && S[y][x+l]; l++) if(num[y+1][x+l+1][1]>=l+1) ret++;
        //DR,R
        for(l=1;x+l<W && y+l<H && S[y+l][x+l] && S[y][x+l]; l++) if(num[y+l+1][x+l+1][1]>=l+1) ret++;
        //UL,L
        for(l=1;x-l>=0 && y-l>=0 && S[y-l][x-l] && S[y][x-l]; l++) if(num[y+1][x-l+1][1]>=l+1) ret++;
        //DL,L
        for(l=1;x-l>=0 && y+l<H && S[y+l][x-l] && S[y][x-l]; l++) if(num[y+l+1][x-l+1][1]>=l+1) ret++;
        //UL,UR
        for(l=1;x-l>=0 && x+l<W && y-l>=0 && S[y-l][x-l] && S[y-l][x+l]; l++) if(num[y-l+1][x+l+1][0]>=2*l+1) ret++;
        //DL,DR
        for(l=1;x-l>=0 && x+l<W && y+l<H && S[y+l][x-l] && S[y+l][x+l]; l++) if(num[y+l+1][x+l+1][0]>=2*l+1) ret++;
        //UL,DL
        for(l=1;x-l>=0 && y-l>=0 && y+l<H && S[y-l][x-l] && S[y+l][x-l]; l++) if(num[y+l+1][x-l+1][1]>=2*l+1) ret++;
        //UR,DR
        for(l=1;x+l<W && y-l>=0 && y+l<H && S[y-l][x+l] && S[y+l][x+l]; l++) if(num[y+l+1][x+l+1][1]>=2*l+1) ret++;
    }
    cout << ret << endl;
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}