#include<bits/stdc++.h>
#define MAX   300300
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
set<int> noti[MAX];
set<pair<int,int> > allNoti;
int notiCnt,rem,n,q;
void process(void) {
    scanf("%d%d",&n,&q);
    REP(love,q) {
        int type,val;
        scanf("%d%d",&type,&val);
        if (type==1) {
            noti[val].insert(++notiCnt);
            allNoti.insert(make_pair(notiCnt,val));
            rem++;
        } else if (type==2) {
            while (!noti[val].empty()) {
                int tmp=*noti[val].begin();
                allNoti.erase(make_pair(tmp,val));
                noti[val].erase(noti[val].begin());
                rem--;
            }
        } else {
            while (!allNoti.empty() && allNoti.begin()->fi<=val) {
                int tmp=allNoti.begin()->se;
                noti[tmp].erase(allNoti.begin()->fi);
                allNoti.erase(allNoti.begin());
                rem--;
            }
        }
        printf("%d\n",rem);
    }
}
int main(void) {
    process();
    return 0;
}