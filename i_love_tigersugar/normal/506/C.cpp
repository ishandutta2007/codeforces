#include<bits/stdc++.h>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
typedef long long ll;
const ll INF=(ll)1e13+7LL;
int reqHigh[MAX],grow[MAX];
int n,nDay,allow,cut;
struct Tree {
    int id;
    ll finHigh,timeDie;
    Tree() {
        id=finHigh=timeDie=0;
    }
    Tree(int id,ll x) {
        this->id=id;
        finHigh=x-1LL*grow[id]*nDay;
        timeDie=min((x+1)/grow[id]+((x+1)%grow[id]>0),nDay+1LL);
    }
    void cutTree(void) {
        finHigh+=cut;
        ll tmp=finHigh+1LL*grow[id]*nDay+1;
        timeDie=min(tmp/grow[id]+(tmp%grow[id]>0),nDay+1LL);
    }
    bool needCut(void) const {
        return (finHigh<reqHigh[id]);
    }
    bool operator > (const Tree &t) const {
        if (timeDie!=t.timeDie) return (timeDie<t.timeDie);
        return (reqHigh[id]-finHigh>reqHigh[t.id]-t.finHigh);
    }
    bool operator < (const Tree &t) const {
        return (t>*this);
    }
};
void init(void) {
    scanf("%d%d%d%d",&n,&nDay,&allow,&cut);
    FOR(i,1,n) scanf("%d%d",&reqHigh[i],&grow[i]);
}
bool ok(ll x) {
    priority_queue<Tree> q;
    FOR(i,1,n) q.push(Tree(i,x));
    FOR(i,1,nDay) {
        Tree tmp=q.top();q.pop();
        if (tmp.timeDie<=i) return (false);
        q.push(tmp);
        int used=0;
        while (used<allow) {
            Tree tmp=q.top();q.pop();
            if (!tmp.needCut()) return (true);
            tmp.cutTree();
            q.push(tmp);
            used++;
        }
    }
    Tree tmp=q.top();q.pop();
    return (!tmp.needCut());
}
ll process(void) {
    ll L=1;
    ll R=INF;
    while (true) {
        if (L==R) return (R);
        if (R-L==1) return (ok(L)?L:R);
        ll M=(L+R)>>1;
        if (ok(M)) R=M; else L=M+1;
    }
}
int main(void) {
#ifdef SKY
    freopen("tmp.txt","r",stdin);
#endif // SKY
    init();
    cout<<process()<<endl;
    return 0;
}