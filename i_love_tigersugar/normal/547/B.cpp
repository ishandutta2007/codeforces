#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define left jidsaof
#define right iszjof
using namespace std;
int left[MAX],right[MAX],a[MAX],res[MAX],n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void prepare(void) {
    stack<int> st;
    while (!st.empty()) st.pop();
    FOR(i,1,n) {
        while (!st.empty() && a[st.top()]>=a[i]) st.pop();
        left[i]=st.empty()?1:st.top()+1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    FORD(i,n,1) {
        while (!st.empty() && a[st.top()]>=a[i]) st.pop();
        right[i]=st.empty()?n:st.top()-1;
        st.push(i);
    }
}
void process(void) {
    memset(res,-1,sizeof res);
    FOR(i,1,n) {
        int t=right[i]-left[i]+1;
        res[t]=max(res[t],a[i]);
    }
    FORD(i,n,2) res[i-1]=max(res[i-1],res[i]);
    FOR(i,1,n) printf("%d ",res[i]); printf("\n");
}
int main(void) {
    init();
    prepare();
    process();
    return 0;
}