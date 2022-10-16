#include<bits/stdc++.h>
#define MAX   1111
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
long long a[MAX];
int n,cnt[MAX],fstCnt[MAX];
vector<long long> val;
void init(void) {
    cin>>n;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n) val.push_back(a[i]);
    sort(ALL(val));
    val.resize(unique(ALL(val))-val.begin());
    FOR(i,1,n) {
        int j=lower_bound(ALL(val),a[i])-val.begin();
        cnt[j]++;
        fstCnt[j]++;
    }
}
int solve(int i,int j) {
    if (a[i]==0 && a[j]==0) return (-1);
    vector<int> usedID;
    int id=lower_bound(ALL(val),a[i])-val.begin();
    int jd=lower_bound(ALL(val),a[j])-val.begin();
    usedID.push_back(id);
    usedID.push_back(jd);
    cnt[id]--;
    cnt[jd]--;
    long long cur[5];
    cur[0]=a[i];
    cur[1]=a[j];
    int res=2;
    while (true) {
        cur[res%3]=cur[(res-1)%3]+cur[(res-2)%3];
        int kd=lower_bound(ALL(val),cur[res%3])-val.begin();
        if (kd<val.size() && val[kd]==cur[res%3] && cnt[kd]>0) {
            res++;
            usedID.push_back(kd);
            cnt[kd]--;
        } else {
            FORE(it,usedID) cnt[*it]=fstCnt[*it];
            return (res);
        }
    }
}
void process(void) {
    int cntZero=0;
    FOR(i,1,n) if (a[i]==0) cntZero++;
    int res=max(cntZero,2);
    FOR(i,1,n) FOR(j,i+1,n) {
        maximize(res,solve(i,j));
        maximize(res,solve(j,i));
    }
    printf("%d\n",res);
}
int main(void) {
    init();
    process();
    return 0;
}