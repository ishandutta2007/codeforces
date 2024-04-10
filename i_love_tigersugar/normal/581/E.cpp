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
#define left   ___left
#define right   ___right
#define int long long
using namespace std;
const int INF=(int)1e9+7;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
bool CompFi(const pair<int,int> &a,const pair<int,int> &b) {
    return (a.fi<b.fi);
}
pair<int,int> gas[MAX];
int n,lim,goal,q,minSta;
int min92[MAX],min95[MAX];
int next[MAX][5];
void init(void) {
    cin>>goal>>lim>>n>>q;
    FOR(i,1,n) cin>>gas[i].se>>gas[i].fi;
    sort(gas+1,gas+n+1);
    while (n>0 && gas[n].fi>=goal) n--;
    if (goal-gas[n].fi>lim) minSta=goal-lim;
    else {
        bool ok=false;
        FORD(i,n-1,1) if (gas[i+1].fi-gas[i].fi>lim) {
            minSta=gas[i+1].fi-lim;
            ok=true;
            break;
        }
        if (!ok) minSta=gas[1].fi-lim;
    }
}
void prepare(void) {
    FOR(i,1,3) next[n][i]=n+1;
    FORD(i,n-1,1) FOR(j,1,3) {
        next[i][j]=next[i+1][j];
        next[i][gas[i+1].se]=i+1;
    }
    FORD(i,n,1) {
        int tmp=min(next[i][2],next[i][3]);
        if (gas[i].se==1)
            min92[i]=tmp>n?goal-gas[i].fi:gas[tmp].fi-gas[i].fi+min92[tmp];
        else min92[i]=tmp>n?max(0LL,goal-gas[i].fi-lim):max(0LL,gas[tmp].fi-gas[i].fi-lim)+min92[tmp];
    }
    FORD(i,n,1) {
        int tmp=next[i][3];
        if (gas[i].se==1)
            min95[i]=i==n?0:min95[i+1];
        else if (gas[i].se==2)
            min95[i]=tmp>n?goal-gas[i].fi-min92[i]:
                gas[tmp].fi-gas[i].fi-(min92[i]-min92[tmp])+min95[tmp];
        else min95[i]=tmp>n?max(0LL,goal-gas[i].fi-lim-min92[i]):
            max(0LL,gas[tmp].fi-gas[i].fi-lim-(min92[i]-min92[tmp]))+min95[tmp];
    }
}
pair<int,int> query(int s) {
    if (n==0) return (goal-s<=lim?make_pair(0,0):make_pair(-1,-1));
    if (s<minSta) return (make_pair(-1,-1));
    if (goal-s<=lim) return (make_pair(0,0));
    int fst=upper_bound(gas+1,gas+n+1,make_pair(s,s),CompFi)-gas;
    int req92=min92[fst];
    int req95=min95[fst];
    int rem=lim-(gas[fst].fi-s);
    if (gas[fst].se==1) {
        int tmp=min(next[fst][2],next[fst][3]);
        if (tmp>n) {
            int del=min(rem,goal-gas[fst].fi);
            req92-=del;
            rem-=del;
        } else {
            int del=min(rem,gas[tmp].fi-gas[fst].fi);
            req92-=del;
            rem-=del;
            if (gas[tmp].se==2) {
                int xxx=next[tmp][3];
                if (xxx>n) {
                    int yyy=min(rem,goal-gas[tmp].fi-min92[tmp]);
                    req95-=yyy;
                    rem-=yyy;
                } else {
                    int yyy=min(rem,gas[xxx].fi-gas[tmp].fi-(min92[tmp]-min92[xxx]));
                    req95-=yyy;
                    rem-=yyy;
                }
            }
        }
    } else if (gas[fst].se==2) {
        int tmp=next[fst][3];
        if (tmp>n) {
            int del=min(rem,goal-gas[fst].fi-min92[fst]);
            req95-=del;
            rem-=del;
        } else {
            int del=min(rem,gas[tmp].fi-gas[fst].fi-(min92[fst]-min92[tmp]));
            req95-=del;
            rem-=del;
        }
    }
    return (make_pair(req92,req95));
}
void process(void) {
    REP(love,q) {
        int x;
        cin>>x;
        pair<int,int> res=query(x);
        cout<<res.fi<<" "<<res.se<<"\n";
    }
}
#undef int
int main(void) {
    ios::sync_with_stdio(false);cin.tie(NULL);
    init();
    prepare();
    process();
    return 0;
}