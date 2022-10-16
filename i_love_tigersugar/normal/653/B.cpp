#include<bits/stdc++.h>
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
const string sta="a";
set<string> vst;
vector<string> canFrom[1111];
int n,q;
void init(void) {
    cin>>n>>q;
    REP(love,q) {
        string s,t;
        cin>>s>>t;
        canFrom[t[0]].push_back(s);
    }
}
void process(void) {
    queue<string> q;
    vst.insert(sta);
    q.push(sta);
    while (!q.empty()) {
        string u=q.front();q.pop();
        if (u.size()>=n) continue;
        FORE(it,canFrom[u[0]]) {
            string v=*it+u.substr(1,u.size());
            if (vst.find(v)==vst.end()) {
                vst.insert(v);
                q.push(v);
            }
        }
    }
    int res=0;
    FORE(it,vst) if (it->size()==n) res++;
    cout<<res<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}