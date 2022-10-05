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

int N,L,R;
int X[100],Y[100];
double A[100];
double dest[1<<20];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>L>>R;
    R-=L;
    FOR(i,N) {
        cin>>X[i]>>Y[i]>>x;
        X[i]-=L;
        A[i]=atan(1)*x/45;
    }
    
    for(int mask=0;mask<1<<N;mask++) {
        FOR(i,N) if((mask & (1<<i))==0) {
            double dx=dest[mask]-X[i];
            double dy=-Y[i];
            double ex=dx*cos(A[i])-dy*sin(A[i]);
            double ey=dx*sin(A[i])+dy*cos(A[i]);
            if(ey>=0) return _P("%d\n",R);
            double tx=X[i]-Y[i]*ex/ey;
            dest[mask|(1<<i)] = max(dest[mask|(1<<i)], tx);
            if(dest[mask|(1<<i)]>R) return _P("%d\n",R);
        }
    }
    
    _P("%.12f\n",dest[(1<<N)-1]);
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}