#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const string fi="first";
const string se="second";
int a[MAX];
vector<int> sa,sb;
int n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d",&a[i]);
        if (a[i]>0) sa.push_back(a[i]);
        else sb.push_back(-a[i]);
    }
}
bool better(const vector<int> &a,const vector<int> &b) {
    REP(i,min(a.size(),b.size())) if (a[i]!=b[i]) return (a[i]>b[i]);
    return (a.size()>b.size());
}
string process(void) {
    long long ta=0,tb=0;
    REP(i,sa.size()) ta+=sa[i];
    REP(i,sb.size()) tb+=sb[i];
    cerr<<ta<<endl;
    cerr<<tb<<endl;
    if (ta>tb) return (fi);
    if (ta<tb) return (se);
    if (better(sa,sb)) return (fi);
    if (better(sb,sa)) return (se);
    return (a[n]>0?fi:se);
}
int main(void) {
    init();
    cout<<process()<<endl;
    return 0;
}