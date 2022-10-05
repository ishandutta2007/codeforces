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
char S[5010][5010];
int mat[5001][5001];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>H>>W;
    gets(S[0]);
    FOR(y,H) {
        gets(S[y]);
        for(x=W-1;x>=0;x--) {
            if(S[y][x]=='0') mat[y][x]=0;
            else mat[y][x]=mat[y][x+1] + 1;
        }
    }
    int ret=0;
    FOR(x,W) {
        vector<int> V;
        FOR(y,H) if(mat[y][x]>0) V.push_back(mat[y][x]);
        sort(V.begin(),V.end());
        FOR(i,V.size()) ret=max(ret,V[i]*((int)V.size()-i));
    }
    _P("%d\n",ret);
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}