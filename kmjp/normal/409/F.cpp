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

int A[]={0, 1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51, 1, 2, 1, 14, 1, 2, 2, 14, 1, 6, 1, 4, 2, 2, 1, 52, 2, 5, 1, 5, 1, 15, 2, 13, 2, 2, 1, 13, 1, 2, 4, 267, 1, 4, 1, 5, 1, 4, 1, 50, 1, 2, 3, 4, 1, 6, 1, 52, 15, 2, 1, 15, 1, 2, 1, 12, 1, 10, 1, 4, 2};
void solve() {
    int f,i,j,k,l,x,y;
    cin>>x;
    cout << A[x] << endl;
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}