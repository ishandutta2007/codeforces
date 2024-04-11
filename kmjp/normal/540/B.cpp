#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K,P,X,Y;
vector<int> A;
int sum,suby;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>K>>P>>X>>Y;
    FOR(i,K) cin>>x, sum+=x, suby+=(x<Y);
    
    FOR(i,N-K) {
        if(suby<N/2) sum++, A.push_back(1), suby++;
        else sum+=Y, A.push_back(Y);
    }
    if(suby>N/2) return _P("-1\n");
    if(sum>X) return _P("-1\n");
    
    FORR(r,A) if(r) _P("%d ",r);
    _P("\n");
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}