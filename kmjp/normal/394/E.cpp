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
ll CX1,CY1,C;
int NX[100001],NY[100001];
double X[100001],Y[100001];

bool inside(double x,double y) {
    int lr=0,i;
    FOR(i,M) {
        double cr=(x-X[i])*(y-Y[(i+1)%M])-(y-Y[i])*(x-X[(i+1)%M]);
        if(cr<0) lr |= 1;
        if(cr>0) lr |= 2;
    }
    return (lr==1 || lr==2);
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    FOR(i,N) {
        cin>>x>>y;
        CX1 += -2*x;
        CY1 += -2*y;
        C += x*(ll)x + y*(ll)y;
    }
    cin>>M;
    FOR(i,M) cin>>X[i]>>Y[i];
    
    double mix=CX1/(-2.0)/N,miy=CY1/(-2.0)/N;
    
    if(inside(mix,miy)) {
        double r = N*(mix*mix+miy*miy) + CX1*mix + CY1*miy + C;
        _P("%.12lf\n",r);
        return;
    }
    double mi=1e20;
    
    FOR(i,M) {
        mi=min(mi, N*(X[i]*X[i]+Y[i]*Y[i]) + CX1*X[i] + CY1*Y[i] + C);
        double x1=X[i],y1=Y[i],x2=X[(i+1)%M],y2=Y[(i+1)%M];
        double aa = N*((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        double bb = 2*N*((x2-x1)*x1+(y2-y1)*y1) + CX1*(x2-x1) + CY1*(y2-y1);
        double t = bb/(-2.0)/aa;
        if(t<=0 || t>=1) continue;
        double nx=t*(x2-x1)+x1;
        double ny=t*(y2-y1)+y1;
        mi=min(mi, N*(nx*nx+ny*ny) + CX1*nx + CY1*ny + C);
    }
    _P("%.12lf\n",mi);
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}