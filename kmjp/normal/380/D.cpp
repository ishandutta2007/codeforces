#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[101000];
map<int,int> M;
ll mo=1000000007;
vector<int> L,R,I;

ll modpow(ll a, ll n) {
    ll r=1;
    while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
    return r;
}
ll comb(int P_,int Q_) {
    if(P_<0 || Q_<0 || Q_>P_) return 0;
    ll ret=1;
    Q_=min(Q_,P_-Q_);
    for(int i=1;i<=Q_;i++) ret=ret*(P_+1-i)%mo*modpow(i,mo-2)%mo;
    return ret;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) {
        cin>>A[i];
        if(A[i]) M[A[i]]=i;
    }
    if(M.empty()) return _P("%lld\n",modpow(2,N-1));
    
    ITR(it,M) {
        I.push_back(it->second);
        if(it==M.begin()) {
            l=r=it->second;
            L.push_back(-2);
            R.push_back(-2);
        }
        else {
            if(it->second<l) {
                l=it->second;
                L.push_back(l);
                R.push_back(-2);
            }
            else if(it->second>r) {
                r=it->second;
                L.push_back(-2);
                R.push_back(r);
            }
            else return _P("0\n");
        }
    }
    L.push_back(0);
    R.push_back(N-1);
    for(i=L.size()-1;i>=0;i--) if(L[i]==-2) L[i]=L[i+1];
    for(i=L.size()-1;i>=0;i--) if(R[i]==-2) R[i]=R[i+1];
    
    ll lt=0,rt=0;
    x=M.begin()->first;
    y=M.begin()->second;
    map<pair<int,int>, ll> V;
    if(x==1) V[make_pair(y,y)]=1;
    else {
        if(y-L[0]>=x-1) V[make_pair(y-(x-1),y)]+=modpow(2,x-2);
        if(R[0]-y>=x-1) V[make_pair(y,y+(x-1))]+=modpow(2,x-2);
    }
    
    for(i=1;i<L.size()-1;i++) {
        map<pair<int,int>, ll> V2;
        
        ITR(it,V) {
            if(it->first.second<I[i]) {
                l=I[i]-(A[I[i]]-1);
                if(l<L[i] || l>it->first.first) continue;
                x=it->first.first-l;
                y=I[i]-it->first.second;
                V2[make_pair(l,I[i])] += comb(x+y-1,x)*it->second%mo;
            }
            if(I[i]<it->first.second) {
                r=I[i]+(A[I[i]]-1);
                if(r>R[i] || r<it->first.second) continue;
                x=it->first.first-I[i];
                y=r-it->first.second;
                V2[make_pair(I[i],r)] += comb(x+y-1,y)*it->second%mo;
            }
        }
        V=V2;
    }
    
    ll ret=0;
    ITR(it,V) {
        x=it->first.first;
        y=(N-1)-it->first.second;
        ret += comb(x+y,y)*it->second%mo;
    }
    cout<<ret%mo<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}