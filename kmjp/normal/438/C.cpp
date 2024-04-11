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
ll X[300],Y[300];
ll mo=1000000007;

int able[201][201];
ll dpdp[201][201];
vector<pair<ll,ll> > VV;

int sgn(ll a) {
    if(a>0) return 1;
    if(a<0) return -1;
    return 0;
}

int inside(double x,double y,vector<pair<ll,ll> >& V) {
    int num=0,n=V.size(),i;
    // 
    // 0-out 1-in 2-border
    FOR(i,n) if(x==V[i].first && y==V[i].second) return 2; // on point
    FOR(i,n) { // on border
        double dx=V[(i+1)%n].first-V[i].first,dy=V[(i+1)%n].second-V[i].second;
        double dx2=x-V[i].first,dy2=y-V[i].second;
        if(fabs(dx*dy2-dx2*dy)>=1e-9) continue;
        if(dx!=0) {
            if(dx2/dx>=0 && dx2/dx<=1) return 1;
        }
        else if(dy2/dy>=0 && dy2/dy<=1) return 1;
    }
    
    FOR(i,n) { //cross border?
        ll x1=V[i].first,y1=V[i].second;
        ll x2=V[(i+1)%n].first,y2=V[(i+1)%n].second;
        //_P("[%d %d]",i,num);
        if(y1==y2) continue;
        if(y1==y) {
            if(x1>=x && y2<y) num++; // down
        }
        else if(y2==y) {
            if(x2>=x && y1<y) num--; // up
        }
        else if(y1>y && y2<y) { //down
            double xx=x1+(x2-x1)*(double)(y-y1)/(y2-y1);
            if(xx>=x) num++;
        }
        else if(y1<y && y2>y) { //up
            double xx=x1+(x2-x1)*(double)(y-y1)/(y2-y1);
            if(xx>=x) num--;
        }
    }
    //_P("num %lf %lf %d\n",x,y,num);
    return num!=0;
}

int test(int aa,int bb) {
    if((aa+1)%N==bb || (bb+1)%N==aa) return 1;
    int i;
    FOR(i,N) if(i!=aa && i!=bb) {
        ll x1=X[i]-X[aa];
        ll y1=Y[i]-Y[aa];
        ll x2=X[bb]-X[aa];
        ll y2=Y[bb]-Y[aa];
        if(x1*y2-x2*y1!=0) continue;
        if(x2!=0) {
            double d=x1/(double)x2;
            if(d>=0 && d<=1) return 0;
        }
        if(y2!=0) {
            double d=y1/(double)y2;
            if(d>=0 && d<=1) return 0;
        }
    }
    
    FOR(i,N) {
        if(aa==i || bb==i) continue;
        if(aa==(i+1)%N || bb==(i+1)%N) continue;
        ll x1=X[(i+1)%N]-X[i];
        ll y1=Y[(i+1)%N]-Y[i];
        ll x2=X[aa]-X[i];
        ll y2=Y[aa]-Y[i];
        ll x3=X[bb]-X[i];
        ll y3=Y[bb]-Y[i];
        
        if(sgn(x2*y1-x1*y2)*sgn(x3*y1-x1*y3)>=0) continue;
        x1=X[i]-X[aa];
        y1=Y[i]-Y[aa];
        x2=X[(i+1)%N]-X[aa];
        y2=Y[(i+1)%N]-Y[aa];
        x3=X[bb]-X[aa];
        y3=Y[bb]-Y[aa];
        if(sgn(x2*y3-x3*y2)*sgn(x1*y3-x3*y1)>=0) continue;
        
        return 0;
    }
    double xx1=X[bb]-X[aa];
    double yy1=Y[bb]-Y[aa];
    double rr=sqrt(xx1*xx1+yy1*yy1);
    xx1=X[aa]+xx1/10/rr;
    yy1=Y[aa]+yy1/10/rr;
    //_P("++%d %d %lf %lf %d\n",aa,bb,xx1,yy1);
    return inside(xx1,yy1,VV)>0;
}

ll dodo(int s,int e) {
    if(dpdp[s][e]>=0) return dpdp[s][e];
    if(able[s][e]==0) return dpdp[s][e]=0;
    if(s+2>=e) return dpdp[s][e]=1;
    dpdp[s][e]=0;
    for(int x=s+1;x<e;x++) if(able[s][x] && able[x][e] && able[e][s])
        dpdp[s][e]=(dpdp[s][e] + dodo(s,x)*dodo(x,e)) % mo;
    return dpdp[s][e];
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    FOR(i,N) cin>>X[i]>>Y[i];
    FOR(i,N) VV.push_back(make_pair(X[i],Y[i]));
    
    FOR(x,N) for(y=x+1;y<N;y++) able[x][y]=able[y][x]=test(x,y);
    //FOR(x,N) for(y=x+1;y<N;y++) if(able[x][y]) _P("%d %d\n",x,y);
    MINUS(dpdp);
    //FOR(x,N) for(y=x+1;y<N;y++) for(i=y+1;i<N;i++) if(able[x][y]&&able[y][i]&&able[i][x]) _P("*%d %d %d\n",x,y,i);
    cout << dodo(0,N-1) << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}