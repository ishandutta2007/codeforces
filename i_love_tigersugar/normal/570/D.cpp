#include<bits/stdc++.h>
#define MAX   500500
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define MASK(i) (1<<(i))
using namespace std;
const char yes[]="Yes";
const char no[]="No";
class FenwickTree {
    private:
    int n;
    vector<int> v;
    int get(int x) const {
        int res=0;
        for (;x>=1;x&=x-1) res^=v[x];
        return (res);
    }
    public:
    FenwickTree() {
        n=0;
    }
    FenwickTree(int n) {
        this->n=n;
        v.assign(n+3,0);
    }
    void update(int x,int d) {
        for (;x<=n;x+=x&-x) v[x]^=d;
    }
    int get(int l,int r) const {
        return (l==1?get(r):get(r)^get(l-1));
    }
};
vector<int> child[MAX];
int sta[MAX],fin[MAX],high[MAX];
vector<int> atHigh[MAX];
int n,q,cnt;
char s[MAX];
FenwickTree bit[MAX];
void loadTree(void) {
    scanf("%d%d",&n,&q);
    FOR(i,2,n) {
        int p;
        scanf("%d",&p);
        child[p].push_back(i);
    }
    scanf("%s",s+1);
}
void dfs(int u) {
    sta[u]=++cnt;
    FORE(it,child[u]) {
        high[*it]=high[u]+1;
        dfs(*it);
    }
    fin[u]=cnt;
}
void prepare(void) {
    high[1]=1;
    dfs(1);
    FOR(i,1,n) atHigh[high[i]].push_back(sta[i]);
    FOR(i,1,n) if (!atHigh[i].empty()) {
        sort(ALL(atHigh[i]));
        bit[i]=FenwickTree(atHigh[i].size());
    }
    FOR(i,1,n) {
        int pos=lower_bound(ALL(atHigh[high[i]]),sta[i])-atHigh[high[i]].begin()+1;
        bit[high[i]].update(pos,MASK(s[i]-'a'));
    }
}
bool answer(int u,int h) {
    if (atHigh[h].empty()) return (true);
    int L=lower_bound(ALL(atHigh[h]),sta[u])-atHigh[h].begin()+1;
    int R=upper_bound(ALL(atHigh[h]),fin[u])-atHigh[h].begin()+1;
    if (L>=R) return (true);
    return (__builtin_popcount(bit[h].get(L,R-1))<=1);
}
void process(void) {
    REP(love,q) {
        int u,h;
        scanf("%d%d",&u,&h);
        printf("%s\n",answer(u,h)?yes:no);
    }
}
int main(void) {
    loadTree();
    prepare();
    process();
    return 0;
}