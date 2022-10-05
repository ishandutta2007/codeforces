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

int N,M,K,P;
ll H[101000],A[101000];

bool ok(ll V) {
    ll tot=0;
    int i;
    FOR(i,N) tot += max(0LL, (H[i]+M*A[i]-V+(P-1))/P);
    if(tot>M*K) return false;
    int day[5005]={};
    FOR(i,N) {
        if(H[i]+M*A[i]<=V) continue;
        ll dif=H[i]+M*A[i]-V;
        for(ll d=(dif%P==0)?P:dif%P; d<=dif; d+=P) {
            ll da=max((d-H[i]+A[i]-1)/A[i],0LL);
            if(da>=M) return false;
            day[da]++;
        }
    }
    ll left=0;
    FOR(i,M) {
        left += day[i];
        left = max(0LL,left-K);
    }
    return left==0;
    
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M>>K>>P;
    FOR(i,N) cin>>H[i]>>A[i];
    
    ll ret=(1LL<<50)-1;
    for(i=49;i>=0;i--) if(ok(ret-(1LL<<i))) ret -= 1LL<<i;
    cout<< ret << endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}