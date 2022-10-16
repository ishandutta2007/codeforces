#include<bits/stdc++.h>
#define MAX   227
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
struct State {
    int r,g,b;
    State() {
        r=g=b=0;
    }
    State(int _r,int _g,int _b) {
        r=_r;g=_g;b=_b;
    }
};
queue<State> q;
bool vst[MAX][MAX][MAX];
int r,g,b;
void addState(int r,int g,int b) {
    if (vst[r][g][b]) return;
    vst[r][g][b]=true;
    q.push(State(r,g,b));
}
void process(void) {
    string s;
    cin>>s>>s;
    FORE(it,s) {
        if (*it=='R') r++;
        if (*it=='G') g++;
        if (*it=='B') b++;
    }
    vst[r][g][b]=true;
    q.push(State(r,g,b));
    while (!q.empty()) {
        int ur=q.front().r;
        int ug=q.front().g;
        int ub=q.front().b;
        q.pop();
        if (ur>1) addState(ur-1,ug,ub);
        if (ug>1) addState(ur,ug-1,ub);
        if (ub>1) addState(ur,ug,ub-1);
        if (ur>0 && ug>0) addState(ur-1,ug-1,ub+1);
        if (ug>0 && ub>0) addState(ur+1,ug-1,ub-1);
        if (ub>0 && ur>0) addState(ur-1,ug+1,ub-1);
    }
    if (vst[0][0][1]) printf("B");
    if (vst[0][1][0]) printf("G");
    if (vst[1][0][0]) printf("R");
    printf("\n");
}
int main(void) {
    process();
    return 0;
}