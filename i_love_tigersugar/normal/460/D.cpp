#include<cassert>
#include<iostream>
#include<vector>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define BIT(x,i) (((x)>>(i))&1)
using namespace std;
typedef long long ll;
const ll INF=(ll)1e18+7LL;
const int nb=45;
inline ll nextLong(void) {
    ll x;
    cin>>x;
    return (x);
}
ll l,r,k;
ll best;
struct state {
    bool ok;
    ll a,b,c;
    state() {
        ok=a=b=c=0;
    }
    state(bool x,ll _a,ll _b,ll _c) {
        ok=x;a=_a;b=_b;c=_c;
    }
    void update(const state &s,int i,int na,int nb,int nc) {
        if (ok) return;
        ok=true;a=s.a;b=s.b;c=s.c;
        if (na) a|=1LL<<i;
        if (nb) b|=1LL<<i;
        if (nc) c|=1LL<<i;
    }
};
state f[50][2][2][2][2][2][2][2][2][2];
vector<ll> res,cur;
void init(void) {
    l=nextLong();
    r=nextLong();
    k=nextLong();
}
void backtrack(ll val,int cnt,ll sxor) {
    REP(i,2) if (cnt+i<=k) {
        ll tmp=sxor;
        if (i) tmp^=val;
        if (i) cur.push_back(val);
        if (val==r) {
            if (tmp<best && !cur.empty()) {
                best=tmp;
                res=cur;
            }
        }
        else backtrack(val+1,cnt+i,tmp);
        if (i) cur.pop_back();
    }
}
bool canzero(void) {
    f[0][1][1][1][1][1][1][0][0][0]=state(true,0,0,0);
    REP(i,nb) REP(xa,2) REP(xb,2) REP(xc,2) REP(ya,2) REP(yb,2) REP(yc,2) REP(ab,2) REP(bc,2) REP(ca,2)
        if (f[i][xa][xb][xc][ya][yb][yc][ab][bc][ca].ok) REP(na,2) REP(nb,2) REP(nc,2) if ((na^nb^nc)==0) {
            int za=(na==BIT(l,i)&&xa)||na>BIT(l,i);
            int zb=(nb==BIT(l,i)&&xb)||nb>BIT(l,i);
            int zc=(nc==BIT(l,i)&&xc)||nc>BIT(l,i);
            int ta=(na==BIT(r,i)&&ya)||na<BIT(r,i);
            int tb=(nb==BIT(r,i)&&yb)||nb<BIT(r,i);
            int tc=(nc==BIT(r,i)&&yc)||nc<BIT(r,i);
            int ba=ab||na!=nb;
            int cb=bc||nb!=nc;
            int ac=ca||nc!=na;
            f[i+1][za][zb][zc][ta][tb][tc][ba][cb][ac].update(f[i][xa][xb][xc][ya][yb][yc][ab][bc][ca],i,na,nb,nc);
        }
    state tmp=f[nb][1][1][1][1][1][1][1][1][1];
    if (!tmp.ok) return (false);
    cout<<"0\n3\n"<<tmp.a<<" "<<tmp.b<<" "<<tmp.c<<endl;
    return (true);
}
void process(void) {
    if (k>=4) {
        if (r-l+1<=10) {
            best=INF;
            backtrack(l,0,0);
            cout<<best<<endl<<res.size()<<endl;
            REP(i,res.size()) cout<<res[i]<<" ";
        }
        else {
            ll t=l;
            while (t%4!=0) t++;
            cout<<"0\n4\n";
            REP(i,4) cout<<t+i<<" ";
        }
    }
    else if (k==3) {
        if (canzero()) return;
        else {
            ll t=l;
            while (t%2!=0) t++;
            cout<<"1\n2\n";
            REP(i,2) cout<<t+i<<" ";
        }
    }
    else if (k==2) {
        if (r-l>=2 || l%2==0) {
            ll t=l;
            while (t%2!=0) t++;
            cout<<"1\n2\n";
            REP(i,2) cout<<t+i<<" ";
        }
        else {
            ll t=l^r;
            if (t<l) cout<<t<<endl<<"2\n"<<l<<" "<<r;
            else cout<<l<<endl<<"1\n"<<l;
        }
    }
    else cout<<l<<endl<<"1\n"<<l;
}
int main(void) {
    init();
    process();
    return 0;
}