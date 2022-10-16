#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int n,maxValue,m;
set<vector<int> > ans;
int value(const vector<int> &v) {
    int res=0;
    REP(i,n) FOR(j,i,n-1) {
        int tmp=10000;
        FOR(k,i,j) tmp=min(tmp,v[k]);
        res+=tmp;
    }
    return (res);
}
void process(void) {
    cin>>n>>m;
    vector<int> v;
    REP(i,n) v.push_back(i+1);
    do maxValue=max(maxValue,value(v)); while (next_permutation(v.begin(),v.end()));
    sort(v.begin(),v.end());
    do if (value(v)==maxValue) ans.insert(v); while (next_permutation(v.begin(),v.end()));
    __typeof(ans.begin()) it=ans.begin();
    REP(zz,m-1) it++;
    REP(i,n) printf("%d ",(*it)[i]); printf("\n");
}
int main(void) {
    process();
    return 0;
}