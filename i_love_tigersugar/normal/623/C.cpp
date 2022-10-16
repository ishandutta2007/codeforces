#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define SQR(x) (1LL*(x)*(x))
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
const long long INF=(long long)1e18+7LL;
const int limC=(int)1e9+7;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
pair<int,int> point[MAX];
int minLeft[MAX],minRight[MAX],maxLeft[MAX],maxRight[MAX];
int n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&point[i].fi,&point[i].se);
    sort(point+1,point+n+1);
}
void prepare(void) {
    minLeft[1]=maxLeft[1]=point[1].se;
    FOR(i,2,n) {
        minLeft[i]=min(minLeft[i-1],point[i].se);
        maxLeft[i]=max(maxLeft[i-1],point[i].se);
    }
    minRight[n]=maxRight[n]=point[n].se;
    FORD(i,n-1,1) {
        minRight[i]=min(minRight[i+1],point[i].se);
        maxRight[i]=max(maxRight[i+1],point[i].se);
    }
}
bool checkX(long long r) {
    int maxVal=point[1].fi;
    int minVal=point[1].fi;
    FOR(i,1,n) {
        minimize(minVal,point[i].fi);
        maximize(maxVal,point[i].fi);
    }
    return (maxVal-minVal<=r);
}
bool checkY(long long r) {
    int maxVal=point[1].se;
    int minVal=point[1].se;
    FOR(i,1,n) {
        minimize(minVal,point[i].se);
        maximize(maxVal,point[i].se);
    }
    return (maxVal-minVal<=r);
}
long long getSQRT(long long x) {
    long long t=sqrt(x);
    FOR(i,-10,10) if (i+t>=0 && SQR(i+t)>x) return (i+t-1);
    assert(false);
}
bool CompX(const pair<int,int> &a,const pair<int,int> &b) {
    return (a.fi<b.fi);
}
bool ok(long long bigR) {
    long long smallR=getSQRT(bigR);
    if (checkX(smallR) || checkY(smallR)) return (true);
    FOR(i,1,n) {
        long long minX,maxX;
        if (point[i].fi==0) minX=maxX=0;
        else if (point[i].fi>0) {
            maxX=point[i].fi;
            minX=max(0LL-point[i].fi,maxX-smallR);
        } else {
            minX=point[i].fi;
            maxX=min(0LL-point[i].fi,minX+smallR);
        }
        minimize(maxX,limC);
        maximize(minX,-limC);
        int L=lower_bound(point+1,point+n+1,pair<int,int>(minX,minX),CompX)-point;
        int R=upper_bound(point+1,point+n+1,pair<int,int>(maxX,maxX),CompX)-point-1;
        int maxY=-limC;
        int minY=limC;
        if (L>1) {
            maximize(maxY,maxLeft[L-1]);
            minimize(minY,minLeft[L-1]);
        }
        if (R<n) {
            maximize(maxY,maxRight[R+1]);
            minimize(minY,minRight[R+1]);
        }
        if (maxY<minY) return (true);
        if (maxY-minY<=smallR && max(SQR(maxX),SQR(minX))+max(SQR(maxY),SQR(minY))<=bigR) return (true);
    }
    return (false);
}
long long process(void) {
    long long L=0;
    long long R=INF;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (ok(L)?L:R);
        long long M=(L+R)>>1;
        if (ok(M)) R=M; else L=M+1;
    }
}
int main(void) {
    init();
    prepare();
    cout<<process()<<endl;
    return 0;
}