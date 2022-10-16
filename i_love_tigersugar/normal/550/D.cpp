#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
using namespace std;
int k;
void init(void) {
    scanf("%d",&k);
    if (k%2==0) {
        printf("NO\n");
        exit(0);
    }
    if (k==1) {
        printf("YES\n2 1\n1 2\n");
        exit(0);
    }
}
set<pair<int,int> > edge;
void addEdge(int u,int v) {
    if (u>v) swap(u,v);
    edge.insert(make_pair(u,v));
}
void process(void) {
    printf("YES\n");
    int n=1;
    REP(love,k) addEdge(1,++n);
    FOR(i,2,k+1) REP(love,k-1) addEdge(i,++n);
    vector<int> leaf;
    FOR(i,k+2,2*k) REP(love,k-1) {
        leaf.push_back(++n);
        addEdge(i,leaf.back());
    }
    for (int i=0;i+(k-1)*(k-1)-1<leaf.size();i=i+(k-1)*(k-1)) {
        vector<int> cur;
        REP(j,(k-1)*(k-1)) cur.push_back(leaf[i+j]);
        REP(j,cur.size()) if (j%2==0) {
            int t=j%(k-1)+1;
            REP(x,k-1) addEdge(cur[j],cur[x*(k-1)+t]);
        }
    }
    vector<int> cur;
    REP(j,(k-1)*(k-1)) cur.push_back(2*k+j+1);
    REP(j,cur.size()) if (j%2==0) {
        int t=j%(k-1)+1;
        REP(x,k-1) addEdge(cur[j],cur[x*(k-1)+t]);
    }
    printf("%d %d\n",n,(int)edge.size());
    FORE(it,edge) printf("%d %d\n",it->fi,it->se);
}
int main(void) {
    init();
    process();
    return 0;
}