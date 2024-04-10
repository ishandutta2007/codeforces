#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
long long floor(long long a,long long b) {
    assert(b>0);
    long long x=a/b;
    FORD(i,2,-2) if (b*(x+i)<=a) return (x+i);
    assert(false);
}
long long ceil(long long a,long long b) {
    assert(b>0);
    long long x=a/b;
    FOR(i,-2,2) if (b*(x+i)>=a) return (x+i);
    assert(false);
}
long long gcd(long long a,long long b) {
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a>b) a%=b; else b%=a;
    }
}
long long calcNumber(long long a1,long long a2,long long b1,long long b2,long long L,long long R) {
    maximize(L,b1);
    maximize(L,b2);
    long long d=gcd(a1,a2);
    if ((b2-b1)%d!=0) return (0);
    long long c1=a1/d;
    long long c2=a2/d;
    long long c=(b2-b1)/d;
    long long r[2],s[2],t[2];
    r[0]=c1;s[0]=1;t[0]=0;
    r[1]=c2;s[1]=0;t[1]=1;
    int cur=1;
    while (r[cur]!=0) {
        int next=cur^1;
        long long q=r[next]/r[cur];
        r[next]-=q*r[cur];
        s[next]-=q*s[cur];
        t[next]-=q*t[cur];
        cur=next;
    }
    assert(r[cur^1]==1);
    //cerr<<r[cur^1]<<" "<<s[cur^1]<<" "<<t[cur^1]<<endl;
    long long valX=s[cur^1]%c2*c%c2;
    if (valX<0) valX+=c2;
    assert((valX*c1-c)%c2==0);
    long long minX=ceil(L-b1,a1);
    long long maxX=floor(R-b1,a1);
    if (minX>maxX) return (0);
    long long minK=ceil(minX-valX,c2);
    long long maxK=floor(maxX-valX,c2);
    if (minK>maxK) return (0);
    return (maxK-minK+1);
}
int main(void) {
    long long a1,b1,a2,b2,L,R;
    cin>>a1>>b1>>a2>>b2>>L>>R;
    cout<<calcNumber(a1,a2,b1,b2,L,R)<<endl;
    return 0;
}