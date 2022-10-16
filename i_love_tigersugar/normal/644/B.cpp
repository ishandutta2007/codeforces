#include<bits/stdc++.h>
#define MAX   200200
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
struct Job {
    int id,time,dur;
    Job() {
        id=time=dur=0;
    }
    void input(int x) {
        id=x;
        scanf("%d%d",&time,&dur);
    }
    bool operator < (const Job &j) const {
        return (time<j.time);
    }
};
Job job[MAX];
int n,lim;
long long res[MAX];
void init(void) {
    scanf("%d%d",&n,&lim);
    FOR(i,1,n) job[i].input(i);
    sort(job+1,job+n+1);
    FOR(i,1,n) res[i]=-1;
}
void process(void) {
    queue<int> q;
    long long lastTime=0;
    int jobID=1;
    while (true) {
        while (jobID<=n && job[jobID].time<lastTime) {
            if (q.size()<lim) q.push(jobID);
            jobID++;
        }
        int curJob;
        if (q.empty()) {
            if (jobID>n) break;
            curJob=jobID;
            lastTime=job[curJob].time;
            jobID++;
        } else {
            curJob=q.front();q.pop();
        }
        lastTime+=job[curJob].dur;
        res[job[curJob].id]=lastTime;
    }
    FOR(i,1,n) cout<<res[i]<<" ";
    cout<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}