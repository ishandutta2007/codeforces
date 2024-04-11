#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N,M,A[100001];
vector<int> V[100001];
ll S[100002];
void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M;
    FOR(i,M) cin>>A[i];
    
    ll ret=0;
    FOR(i,M) if(i>0 && A[i]!=A[i-1]) V[A[i]].push_back(A[i-1]), ret+=abs(A[i]-A[i-1]);
    FOR(i,M) if(i<M-1 && A[i]!=A[i+1]) V[A[i]].push_back(A[i+1]), ret+=abs(A[i]-A[i+1]);
    ret/=2;
    
    ll ma=0;
    FOR(i,N+1) {
        sort(V[i].begin(),V[i].end());
        S[0]=0;
        ll cm=0;
        FOR(j,V[i].size()) S[j]=((j>0)?S[j-1]:0)+V[i][j], cm+=abs(i-V[i][j]);
        FOR(j,V[i].size()) {
            ll dd=(j+1)*(ll)V[i][j]-S[j]+(S[V[i].size()-1]-S[j])-(V[i].size()-(j+1))*(ll)V[i][j];
            ma=max(ma,cm-dd);
        }
    }
    cout << ret-ma << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}