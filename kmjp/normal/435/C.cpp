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
char S[2002][2002];

void solve() {
    int f,i,j,k,l,x,y,x2,y2,s=0;
    
    cin>>N;
    FOR(x,2002) FOR(y,2002) S[x][y]=' ';
    x=0;y=1001;
    FOR(i,N) {
        cin>>j;
        s+=j;
        FOR(f,j) {
            if(i%2) S[y][x]='\\';
            else S[y][x]='/';
            
            x++;
            if(f!=j-1) {
                if(i%2) y++;
                else y--;
            }
        }
    }
    FOR(y,2002) S[y][s]=0;
    FOR(y,2002) if(count(S[y],S[y]+s,' ')!=s) printf("%s\n",S[y]);
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}