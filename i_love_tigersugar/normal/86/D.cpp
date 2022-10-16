#include<bits/stdc++.h>
#define MAX   200200
#define MAXV   1000100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
using namespace std;
struct Query {
    int l,r,id;
    Query() {
        l=r=id=0;
    }
    Query(int _l,int _r,int _id) {
        l=_l;r=_r;id=_id;
    }
    bool operator < (const Query &q) const {
        return (r<q.r);
    }
};
int n,q,blockSize;
int a[MAX],cnt[MAXV];
vector<pair<int,int> > queryAt[MAX];
long long answer[MAX],rightSum;
void init(void) {
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,q) {
        int l,r;
        scanf("%d%d",&l,&r);
        queryAt[l].push_back(make_pair(r,i));
    }
    FOR(i,1,n) if (!queryAt[i].empty()) sort(ALL(queryAt[i]));
    while (1LL*blockSize*blockSize<=n) blockSize++;
}
long long getAnswer(int l,int r) {
    long long res=rightSum;
    FOR(i,l,r) {
        cnt[a[i]]++;
        res+=(2*cnt[a[i]]-1LL)*a[i];
    }
    FOR(i,l,r) cnt[a[i]]--;
    return (res);
}
void process(void) {
    int blockL=1;
    while (blockL<=n) {
        int blockR=min(blockL+blockSize-1,n);
        memset(cnt,0,sizeof cnt);
        rightSum=0;
        vector<Query> outQuery;
        FOR(i,blockL,blockR) FORE(it,queryAt[i]) {
            if (it->fi<=blockR) answer[it->se]=getAnswer(i,it->fi);
            else outQuery.push_back(Query(i,it->fi,it->se));
        }
        sort(ALL(outQuery));
        int pos=blockR;
        FORE(it,outQuery) {
            while (pos<it->r) {
                pos++;
                cnt[a[pos]]++;
                rightSum+=(2*cnt[a[pos]]-1LL)*a[pos];
            }
            answer[it->id]=getAnswer(it->l,blockR);
        }
        blockL+=blockSize;
    }
    FOR(i,1,q) cout<<answer[i]<<"\n";
}
int main(void) {
    srand(time(NULL));
    init();
    process();
    return 0;
}