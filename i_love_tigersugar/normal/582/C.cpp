#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int gcd(int a,int b) {
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a>b) a%=b; else b%=a;
    }
}
int a[MAX],cnt[MAX],n;
bool isMax[MAX];
vector<int> can[MAX];
void init(void) {
    scanf("%d",&n);
    REP(i,n) scanf("%d",&a[i]);
    FOR(i,1,n-1) can[gcd(i,n)].push_back(i);
}
long long checkGCD(int d) {
    vector<int> &can=::can[d];
    int id=0;
    FOR(i,1,n-1) {
        cnt[i]=cnt[i-1];
        while (id<can.size() && can[id]<i) id++;
        if (id<can.size() && can[id]==i) cnt[i]++;
    }
    memset(isMax,false,sizeof isMax);
    REP(i,d) {
        int maxVal=a[i];
        for (int j=i;j<n;j=j+d) maximize(maxVal,a[j]);
        for (int j=i;j<n;j=j+d) if (maxVal==a[j]) isMax[j]=true;
    }
    long long res=0;
    int j=0;
    REP(i,n) {
        while (j-i<n-1 && isMax[j%n]) j++;
        if (j>i) res+=cnt[j-i]; else j=i+1;
    }
    return (res);
}
void process(void) {
    long long res=0;
    FOR(i,1,n-1) if (n%i==0) res+=checkGCD(i);
    cout<<res<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}