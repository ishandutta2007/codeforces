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

int N,K,A[1001];
vector<pair<int,int> > V;
void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>K;
    FOR(i,N) cin>>A[i];
    FOR(i,K) {
        x=min_element(A,A+N)-A;
        y=max_element(A,A+N)-A;
        if(A[x]+1<A[y]) {
            V.push_back(make_pair(y+1,x+1));
            A[y]--;
            A[x]++;
        }
    }
    x=min_element(A,A+N)-A;
    y=max_element(A,A+N)-A;
    _P("%d %d\n",*max_element(A,A+N)-*min_element(A,A+N), V.size()) ;
    FOR(i,V.size()) _P("%d %d\n",V[i].first,V[i].second);
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}