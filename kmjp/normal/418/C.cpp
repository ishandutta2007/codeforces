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

int N,M;
vector<int> MM[101];
void solve() {
    int f,i,j,k,l,x,y,z;
    
    cin>>N>>M;
    MM[1].push_back(1);
    MM[2].push_back(3);
    MM[2].push_back(4);
    FOR(x,101) FOR(y,101) FOR(z,101) {
        if(x+y+z>=3 && x+y+z<=100) {
            int hoge=x+y*4+z*9;
            int aa=sqrt(hoge+0.1);
            while(aa*aa<hoge)aa++;
            while(aa*aa>hoge)aa--;
            while(aa*aa<hoge)aa++;
            while(aa*aa>hoge)aa--;
            if(aa*aa==hoge && MM[x+y+z].empty()) {
                FOR(i,x) MM[x+y+z].push_back(1);
                FOR(i,y) MM[x+y+z].push_back(2);
                FOR(i,z) MM[x+y+z].push_back(3);
            }
        }
    }
    FOR(y,N) {
        FOR(x,M) _P("%d ",MM[N][y]*MM[M][x]);
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