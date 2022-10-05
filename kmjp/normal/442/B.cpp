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
double P[101];

double dodo(int L,int R) {
    double fail=1,ma=0;
    int i;
    for(i=L;i<R;i++) fail*=1-P[i];
    for(i=L;i<R;i++) ma+=fail/(1-P[i])*P[i];
    return ma;
}

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N;
    FOR(i,N) {
        cin>>P[i];
        if(P[i]==1) return _P("1.0\n");
    }
    sort(P,P+N);
    double ma=0;
    FOR(x,N) for(y=x+1;y<=N;y++) ma=max(ma,dodo(x,y));
    _P("%.12lf\n",ma);
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}