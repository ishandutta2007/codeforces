#include<algorithm>
#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
int firstTime[MAX],choose[MAX],pos[MAX],w[MAX],n,m;
stack<int> st;
bool CompPos(const int &x,const int &y) {
    return (firstTime[x]>firstTime[y]);
}
void init(void) {
    scanf("%d%d",&n,&m);
    memset(firstTime,0x3f,sizeof firstTime);
    FOR(i,1,n) scanf("%d",&w[i]);
    FOR(i,1,m) {
        scanf("%d",&choose[i]);
        if (firstTime[choose[i]]>i) firstTime[choose[i]]=i;
    }
    FOR(i,1,n) pos[i]=i;
    sort(pos+1,pos+n+1,CompPos);
    FOR(i,1,n) st.push(pos[i]);
}
int totalWeight(int x) {
    int res=0;
    vector<int> v;
    while (true) {
        int t=st.top();st.pop();
        if (t!=x) {
            res+=w[t];
            v.push_back(t);
        } else break;
    }
    while (!v.empty()) {
        st.push(v.back());
        v.pop_back();
    }
    st.push(x);
    return (res);
}
void process(void) {
    int res=0;
    FOR(i,1,m) res+=totalWeight(choose[i]);
    printf("%d\n",res);
}
int main(void) {
    init();
    process();
    return 0;
}