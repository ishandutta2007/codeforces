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
#include <complex>
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

bool sortx(complex<double> l,complex<double> r) { return l.real()<r.real();}
bool sorty(complex<double> l,complex<double> r) { return l.imag()<r.imag();}

double cp_sub2(complex<double>* p,int sz,double d) {
    int x,y;
    sort(p,p+sz,sorty);
    FOR(x,sz) for(y=x+1;y<sz && p[y].imag()-p[x].imag()<d;y++) d=min(d,abs(p[x]-p[y]));
    return d;
}
double cp_sub(complex<double>* p,int sz) {
    
    int x,y,piv;
    if(sz<=5) { // brute force
        double cp=1e20;
        FOR(x,sz) for(y=x+1;y<sz;y++) cp=min(cp,norm(p[x]-p[y]));
        return sqrt(cp);
    }
    piv=sz/2;
    double d=min(cp_sub(p,piv),cp_sub(p+piv,sz-piv));
    vector<complex<double> > V;
    FOR(x,sz) if(fabs(p[x].real()-p[piv].real())<d) V.push_back(p[x]);
    
    return min(d,cp_sub2(&*V.begin(),V.size(),d));
}

double ClosePoint(vector<complex<double> > V) {
    complex<double>* be=&*V.begin();
    sort(be,be+V.size(),sortx);
    return cp_sub(be,V.size());
}

void solve() {
    int f,i,j,k,l,x,y;
    int N;
    vector<complex<double> > C;
    
    cin>>N;
    
    x=0;
    FOR(i,N) {
        cin>>y;
        x+=y;
        C.push_back(complex<double>(i,x));
    }
    double d=ClosePoint(C);
    _P("%lld\n",(ll)(d*d+0.01));
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}