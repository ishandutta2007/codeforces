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
#define DET(s) (s).a][(s).b][(s).c][(s).d
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const char ch[]="XABC";
const char yes[]="YES";
const char no[]="NO";
int getID(char c) {
    REP(i,4) if (ch[i]==c) return (i);
    assert(false);
}
struct State {
    int a,b,c,d;
    State() {
        a=b=c=d=0;
    }
    State(int x,int y,int z,int t) {
        a=x;b=y;c=z;d=t;
    }
    void input(void) {
        char s[4];
        scanf("%s",s);
        a=getID(s[0]);
        b=getID(s[1]);
        scanf("%s",s);
        c=getID(s[0]);
        d=getID(s[1]);
    }
};
bool vst[5][5][5][5][5];
State sta,fin;
void init(void) {
    sta.input();
    fin.input();
}
void addState(queue<State> &q,bool vst[][5][5][5],int a,int b,int c,int d) {
    if (vst[a][b][c][d]) return;
    vst[a][b][c][d]=true;
    q.push(State(a,b,c,d));
}
void bfs(const State &s,bool vst[][5][5][5]) {
    queue<State> q;
    vst[DET(s)]=true;
    q.push(s);
    while (!q.empty()) {
        int a=q.front().a;
        int b=q.front().b;
        int c=q.front().c;
        int d=q.front().d;
        q.pop();
        if (a==0 || b==0) addState(q,vst,b,a,c,d);
        if (a==0 || c==0) addState(q,vst,c,b,a,d);
        if (b==0 || d==0) addState(q,vst,a,d,c,b);
        if (c==0 || d==0) addState(q,vst,a,b,d,c);
    }
}
void process(void) {
    bfs(sta,vst[0]);
    bfs(fin,vst[1]);
    REP(i,4) REP(j,4) REP(k,4) REP(l,4)
        if (vst[0][i][j][k][l] && vst[1][i][j][k][l]) {
            printf("%s\n",yes);
            return;
        }
    printf("%s\n",no);
}
int main(void) {
    init();
    process();
    return 0;
}