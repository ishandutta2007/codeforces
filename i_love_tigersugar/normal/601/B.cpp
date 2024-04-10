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
int a[MAX],b[MAX];
int left[MAX],right[MAX];
int n,q;
void init(void) {
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n-1) b[i]=max(a[i+1]-a[i],a[i]-a[i+1]);
}
void prepare(void) {
    stack<int> st;
    FOR(i,1,n-1) {
        while (!st.empty() && b[st.top()]<=b[i]) st.pop();
        left[i]=st.empty()?0:st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    FORD(i,n-1,1) {
        while (!st.empty() && b[st.top()]<b[i]) st.pop();
        right[i]=st.empty()?n:st.top();
        while (!st.empty() && b[st.top()]<=b[i]) st.pop();
        st.push(i);
    }
}
long long answer(int l,int r) {
    long long res=0;
    FOR(i,l,r-1) res+=1LL*b[i]*(i-max(left[i]+1,l)+1)*(min(right[i],r)-i);
    return (res);
}
void process(void) {
    REP(love,q) {
        int l,r;
        scanf("%d%d",&l,&r);
        cout<<answer(l,r)<<"\n";
    }
}
int main(void) {
    init();
    prepare();
    process();
    return 0;
}