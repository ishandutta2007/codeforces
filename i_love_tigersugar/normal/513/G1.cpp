#include<bits/stdc++.h>
#define MAX   111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
map<vector<int>,double> dp[10];
int nextInt(void) {
    int x;
    assert(scanf("%d",&x)==1);
    return (x);
}
vector<int> revPerm(const vector<int> &v,int l,int r) {
    vector<int> res=v;
    reverse(res.begin()+l,res.begin()+r+1);
    return (res);
}
int inverse(const vector<int> &v) {
    int res=0;
    REP(i,v.size()) FOR(j,i+1,(int)v.size()-1) if (v[i]>v[j]) res++;
    return (res);
}
void process(void) {
    vector<int> fst;
    int n=nextInt();
    int k=nextInt();
    int nWay=n*(n+1)/2;
    REP(zz,n) fst.push_back(nextInt());
    dp[0][fst]=1.0;
    REP(i,k) FORE(it,dp[i]) {
        vector<int> cur=it->fi;
        double prob=it->se;
        REP(l,n) FOR(r,l,n-1) dp[i+1][revPerm(cur,l,r)]+=prob/nWay;
    }
    double res=0.0;
    FORE(it,dp[k]) {
        res+=it->se*inverse(it->fi);
        /*printf("prob of ");
        FORE(jt,it->fi) printf("%d ",*jt);
        printf(" is %.7lf\n",it->se);*/
    }
    printf("%.11lf\n",res);
}
int main(void) {
    process();
    return 0;
}