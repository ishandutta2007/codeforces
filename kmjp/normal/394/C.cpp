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
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int H,W;
int type[3];
string S;
string RS[1000][1000];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>H>>W;
    FOR(y,H) FOR(x,W) {
        cin>>S;
        if(S=="11") type[2]++;
        else if(S=="00") type[0]++;
        else type[1]++;
        RS[y][x]="00";
    }
    
    for(y=0;y<H;y+=2) {
        FOR(x,W) {
            if(type[1] && y<H) RS[y][x]="10",type[1]--;
            if(type[1] && y+1<H) RS[y+1][x]="01",type[1]--;
        }
    }
    for(y=H-1;y>=0;y--) for(x=W-1;x>=0;x--) {
        if(type[2] && RS[y][x]=="00") RS[y][x]="11",type[2]--;
    }
    
    
    FOR(y,H) {
        FOR(x,W) _P("%s ",RS[y][x].c_str());
        _P("\n");
    }
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}