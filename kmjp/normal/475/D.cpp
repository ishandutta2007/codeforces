#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[100050];
int Q;
int X[400050];
map<int,ll> QQ;
map<int,ll> G;
void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>A[i];
    cin>>Q;
    FOR(i,Q) cin>>X[i], QQ[X[i]]=0;
    FOR(i,N) {
        map<int,ll> G2;
        G2[A[i]]=1;
        ITR(it,G) G2[__gcd(it->first,A[i])]+=it->second;
        swap(G,G2);
        ITR(it,G) if(QQ.count(it->first)) QQ[it->first]+=it->second;
    }
    FOR(i,Q) _P("%lld\n",QQ[X[i]]);
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}