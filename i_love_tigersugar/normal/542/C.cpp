#include<bits/stdc++.h>
#define MAX   227
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define next jsoaifa
using namespace std;
typedef unsigned long long ull;
int next[MAX],n;
vector<int> cirLen;
int circle[MAX],dist[MAX];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&next[i]);
}
int findCircle(int x) {
    int res=0;
    int cur=x;
    while (true) {
        res++;
        cur=next[cur];
        if (cur==x) return (res);
        if (res>n+7) return (-1);
    }
}
int findDist(int x) {
    int res=0;
    while (true) {
        if (circle[x]>0) return (res);
        res++;
        x=next[x];
    }
}
ull gcd(ull a,ull b) {
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a>b) a%=b; else b%=a;
    }
}
ull LCM(ull a,ull b) {
    ull t=gcd(a,b);
    return (a/t*b);
}
void process(void) {
    FOR(i,1,n) circle[i]=findCircle(i);
    FOR(i,1,n) dist[i]=findDist(i);
    FOR(i,1,n) if (circle[i]>0) cirLen.push_back(circle[i]);
    sort(ALL(cirLen));
    cirLen.resize(unique(ALL(cirLen))-cirLen.begin());
    ull lcmAll=1;
    FORE(it,cirLen) lcmAll=LCM(lcmAll,*it);
    int maxDist=-1;
    FOR(i,1,n) maxDist=max(maxDist,dist[i]);
    ull res=lcmAll;
    while (res<maxDist) res+=lcmAll;
    cout<<res<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}