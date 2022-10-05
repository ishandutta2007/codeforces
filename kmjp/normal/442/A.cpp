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

int N;
string D[101];
int num[5][5];

void solve() {
    int f,i,j,k,l,x,y,x2,y2;
    
    cin>>N;
    int mask=0;
    FOR(i,N) {
        string s;
        cin>>s;
        x=0;
        if(s[0]=='G') x=1;
        if(s[0]=='B') x=2;
        if(s[0]=='Y') x=3;
        if(s[0]=='W') x=4;
        num[x][s[1]-'1']++;
    }
    int ma=100;
    FOR(i,1<<10) if(ma>__builtin_popcount(i)) {
        int ng=0;
        FOR(y,5) FOR(x,5) FOR(y2,5) FOR(x2,5) {
            if(y==y2 && x==x2) continue;
            if(num[y][x]==0 || num[y2][x2]==0) continue;
            if(y!=y2 && (i&((1<<(y+5))|(1<<(y2+5))))) continue;
            if(x!=x2 && (i&((1<<(x))|(1<<(x2))))) continue;
            ng=1;
        }
        if(ng) continue;
        ma=__builtin_popcount(i);
    }
    cout<<ma<<endl;
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}