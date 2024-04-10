#include<bits/stdc++.h>
#define MAX   666
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for(int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const string no="IMPOSSIBLE";
int minLen[MAX],maxLen[MAX];
int n;
int dpF[MAX][MAX],dpG[MAX][MAX];
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d%d",&minLen[i],&maxLen[i]);
    memset(dpF,-1,sizeof dpF);
    memset(dpG,-1,sizeof dpG);
}
bool f(int l,int r);
bool g(int l,int r) {
    if (l>r) return (true);
    if (dpG[l][r]>=0) return (dpG[l][r]);
    FOR(j,l,r) if (f(l,j) && g(j+1,r)) return (dpG[l][r]=true);
    return (dpG[l][r]=false);
}
bool f(int l,int r) {
    assert(l<=r);
    if (dpF[l][r]>=0) return (dpF[l][r]);
    return (dpF[l][r]=(minLen[l]<=2*(r-l)+1 && 2*(r-l)+1<=maxLen[l] && g(l+1,r)));
}
void trace(int l,int r,string &res) {
    if (l>r) return;
    FOR(j,l,r) if (f(l,j) && g(j+1,r)) {
        res.push_back('(');
        trace(l+1,j,res);
        res.push_back(')');
        trace(j+1,r,res);
        return;
    }
    assert(false);
}
void process(void) {
    if (!g(1,n)) cout<<no<<endl;
    else {
        string res;
        trace(1,n,res);
        cout<<res<<endl;
    }
}
int main(void) {
    init();
    process();
    return 0;
}