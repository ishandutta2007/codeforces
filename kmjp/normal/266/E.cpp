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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#define _D(fmt, ...) printf("%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#define _DE(fmt, ...) fprintf(stderr, "%10s %3d : " fmt,__FUNCTION__,__LINE__,__VA_ARGS__)
#else
#define DBG(...)
#define DV(...)
#define _D(fmt, ...)
#define _DE(fmt, ...)
#endif

typedef signed long long ll;
typedef unsigned long long ull;

#define _PE(...) { printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__); }
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
ll GETi() { ll i;scanf("%lld",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N,M;
ll C[6][6];
ll cv[6][1<<18];
ll vt[6][1<<17];
ll vtt[6][1<<17];

int val[1<<18];
ll MO=1000000007;

void update(int cur, int l,int r,int v) {
    int wi=17,x,y,s,j,k;
    ll tmp=0;
    
    if(cur>=1<<17) {
        FOR(j,6) cv[j][cur]=v;
        return;
    }
    y=cur;
    while(y){ wi--; y>>=1;}
    
    s = (cur<<(wi+1)) & ((1<<17)-1);
    //_P("==%d %d %d %d %d %d\n",cur,l,r,s,1<<wi,v);
    
    if(l==s && r==s+(2<<wi)) {
        val[cur]=v;
        FOR(j,6) cv[j][cur]=(v*vtt[j][(2<<wi)])%MO;
        return;
    }
    
    if(val[cur]!=-1) {
        val[cur*2]=val[cur*2+1]=val[cur];
        FOR(j,6) cv[j][cur*2]=cv[j][cur*2+1]=(val[cur]*vtt[j][(1<<wi)])%MO;
        val[cur]=-1;
    }
    
    if(r<=s+(1<<wi)) update(cur*2,l,r,v);
    else if(l>=s+(1<<wi)) update(cur*2+1,l,r,v);
    else if(l<s+(1<<wi) && r>=s+(1<<wi)) {
        update(cur*2,l,s+(1<<wi),v);
        update(cur*2+1,s+(1<<wi),r,v);
    }
    
    FOR(k,6) {
        cv[k][cur]=(cv[k][cur*2]+cv[k][cur*2+1]) % MO;
        for(j=1;j<=k;j++) {
            cv[k][cur]=(cv[k][cur] + ((cv[k-j][cur*2+1]*vt[j][1<<wi])%MO)*C[k][j])%MO;
        }
    }
    
    
}

vector<ll> queryvec(int cur, int l,int r,int k) {
    vector<ll> ret;
    int wi=17,x,y,s,j,i;
    ll tmp=0;
    
    ret.resize(k+1);
    if(cur>=1<<17) {
        FOR(i,k+1) ret[i]=cv[i][cur];
        return ret;
    }
    y=cur;
    while(y){ wi--; y>>=1;}
    
    s = (cur<<(wi+1)) & ((1<<17)-1);
    //_P("?? %d %d %d %d %d %d %lld %lld\n",cur,l,r,s,1<<wi,k,cv[k][cur],cv[0][cur]);
    
    if(l==s && r==s+(2<<wi)) {
        FOR(i,k+1) ret[i]=cv[i][cur];
        return ret;
    }
    if(val[cur]>=0) {
        FOR(i,k+1) ret[i]=(val[cur]*vtt[i][r-l])%MO;
        return ret;
    }
    if(r<=s+(1<<wi)) return queryvec(cur*2,l,r,k);
    if(l>=s+(1<<wi)) return queryvec(cur*2+1,l,r,k);
    
    vector<ll> le=queryvec(cur*2,l,s+(1<<wi),k);
    vector<ll> ri=queryvec(cur*2+1,s+(1<<wi),r,k);
    FOR(i,k+1) {
        ret[i]=(le[i]+ri[i])%MO;
        
        for(j=1;j<=i;j++) {
            ret[i] = (ret[i] + ((C[i][j]*vt[j][s+(1<<wi)-l])%MO)*ri[i-j]) % MO;
        }
    }
    return ret;
}

ll query(int cur, int l,int r,int k) {
    int wi=17,x,y,s,j;
    ll tmp=0;

    if(cur>=1<<17) return cv[k][cur];
    y=cur;
    while(y){ wi--; y>>=1;}
    
    s = (cur<<(wi+1)) & ((1<<17)-1);
    //_P("?? %d %d %d %d %d %d %lld %lld\n",cur,l,r,s,1<<wi,k,cv[k][cur],cv[0][cur]);
    
    if(l==s && r==s+(2<<wi)) return cv[k][cur];
    if(val[cur]>=0) {
        // lr
        return (val[cur]*vtt[k][r-l])%MO;
    }
    if(r<=s+(1<<wi)) return query(cur*2,l,r,k);
    if(l>=s+(1<<wi)) return query(cur*2+1,l,r,k);
    
    vector<ll> ri=queryvec(cur*2+1,s+(1<<wi),r,k);
    tmp = (query(cur*2,l,s+(1<<wi),k)+ ri[k])%MO;
    for(j=1;j<=k;j++) {
        tmp = (tmp + ((C[k][j]*vt[j][s+(1<<wi)-l])%MO)*ri[k-j]) % MO;
    }
    return tmp;
    
}

void solve() {
    int x,y,i,j,res,TM,nc,l,r;
    char str[10];
    
    ll o,p;
    
    GET2(&N,&M);
    
    FOR(i,N) {
        val[i+(1<<17)]=GETi();
        FOR(j,6) cv[j][i+(1<<17)]=val[i+(1<<17)];
    }
    FOR(i,1<<17) {
        vt[0][i]=1;
        for(j=1;j<=5;j++) vt[j][i]=(vt[j-1][i]*i)%MO;
    }
    FOR(j,6) {
        vtt[j][0]=0;
        for(i=1;i<=1<<17;i++) vtt[j][i]=(vtt[j][i-1]+vt[j][i]) % MO;
    }
    
    C[0][0]=1;
    for(x=1;x<=5;x++) {
        C[x][0]=1;
        for(y=1;y<=x;y++) C[x][y]=C[x-1][y-1]+C[x-1][y];
    }
    
    
    //segtree
    for(i=(1<<17)-1;i>=1;i--) {
        x=17;y=i;
        while(y){ x--; y>>=1;}
        val[i]=-1;
        l=i*2;
        r=i*2+1;
        FOR(j,6) {
            cv[j][i]=(cv[j][l]+cv[j][r])%MO;
            for(y=1;y<=j;y++) cv[j][i]=(cv[j][i] + ((C[j][y]*cv[j-y][r])%MO)*vt[y][1<<x]) % MO;
        }
    }
    
    res=nc=0;
    FOR(i,M) {
        GETs(str);
        GET3(&l,&r,&x);
        l--; r--;
        if(str[0]=='=') {
            update(1,l,r+1,x);
        }
        else {
            query(1,l,r+1,x);
            _P("%lld\n",query(1,l,r+1,x));
        }
    }
    
    
    
    return;
}

int main(int argc,char** argv){
    struct timeval start,end,ts;
    if(argc>1) freopen(argv[1], "r", stdin);
    gettimeofday(&start,NULL);  solve();    gettimeofday(&end,NULL);
    ll span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
    //_E("**Total time: %lld ms\n",span/1000);
    return 0;
}