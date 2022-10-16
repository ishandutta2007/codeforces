#include<bits/stdc++.h>
#define MAX   1000100
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
int cntDig[13],reqDig[13],maxBefore;
string req,best;
void init(void) {
    string big;
    cin>>big>>req;
    FORE(it,big) cntDig[*it-'0']++;
    FORE(it,req) reqDig[*it-'0']++;
    REP(love,MAX) best.push_back('9');
    if (big=="10" || big=="01") {
        cout<<0<<endl;
        exit(0);
    }
}
bool potential(int k) {
    int used[13];
    memset(used,0,sizeof used);
    int tmp=k;
    while (tmp>0) {
        used[tmp%10]++;
        tmp/=10;
    }
    int sumAll=0;
    REP(i,10) {
        if (used[i]+reqDig[i]>cntDig[i]) return (false);
        else sumAll+=cntDig[i]-used[i];
    }
    bool haveNonZero=false;
    FOR(i,1,9) if (cntDig[i]>used[i]) haveNonZero=true;
    return (sumAll==k && haveNonZero);
}
bool better(const string &s,const string &t) {
    if (s.size()!=t.size()) return (s.size()<t.size());
    REP(i,s.size()) if (s[i]!=t[i]) return (s[i]<t[i]);
    return (false);
}
void update(const string &s) {
    if (s[0]=='0') return;
    if (better(s,best)) best=s;
}
void process(void) {
    REP(i,10) if (string(1,i+'0')+req<=req+string(1,i+'0')) maxBefore=i;
    FOR(i,1,MAX) if (potential(i)) {
        int allow[13];
        REP(j,10) allow[j]=cntDig[j]-reqDig[j];
        int tmp=i;
        while (tmp>0) {
            allow[tmp%10]--;
            tmp/=10;
        }
        string can=req;
        REP(j,10) REP(love,allow[j]) can.push_back(j+'0');
        update(can);
        can.clear();
        FOR(j,1,9) if (allow[j]>0) {
            can.push_back(j+'0');
            allow[j]--;
            break;
        }
        FOR(j,0,maxBefore) REP(love,allow[j]) can.push_back(j+'0');
        can+=req;
        FOR(j,maxBefore+1,9) REP(love,allow[j]) can.push_back(j+'0');
        update(can);
    }
    cout<<best<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}