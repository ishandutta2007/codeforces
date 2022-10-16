//This code is based on gridnevvvit's solution
#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
typedef long long ll;
string s[55];
int n,m;
ll notDefine[MASK(20)+7];
double calc[22][22];
double calculate(int i,int k) {
    vector<int> mul,div;
    FOR(j,1,k-i) mul.push_back(j);
    FOR(j,i,k) div.push_back(j);
    double res=1.0;
    while (!mul.empty() || !div.empty()) {
        if (!mul.empty()) {
            res*=mul.back();mul.pop_back();
        }
        if (!div.empty()) {
            res/=div.back();div.pop_back();
        }
    }
    return (res*i);
}
void init(void) {
    cin>>n;
    REP(i,n) cin>>s[i];
    m=s[0].size();
    REP(i,22) REP(j,22) calc[i][j]=calculate(i,j);
}
int stateSame(int x,int y) {
    int res=0;
    REP(i,m) if (s[x][i]==s[y][i]) res|=MASK(i);
    return (res);
}
void process(void) {
    REP(i,n) REP(j,n) if (i!=j) notDefine[stateSame(i,j)]|=MASK(i);
    FORD(i,MASK(m)-1,0) REP(j,m) if (BIT(i,j)) notDefine[i^MASK(j)]|=notDefine[i];
    double res=0.0;
    REP(i,MASK(m)) REP(j,m) if (!BIT(i,j))
        res+=calc[__builtin_popcountll(i)+1][m]*__builtin_popcountll(notDefine[i]^notDefine[i|MASK(j)])/n;
    printf("%.9lf",res);
}
int main(void) {
    init();
    process();
    return 0;
}