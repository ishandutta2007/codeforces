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


int N,M,B[505050];
int num[303030];
ll A[303030];

set<ll> C;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>A[i];
    cin>>M;
    FOR(i,M) cin>>x,num[x-1]++;
    
    if(M%(2*(N-1))==1) {
        cout<< M/(2*(N-1))*2*(A[N-1]-A[0]) << endl;
        return;
    }
    
    ll per=0;
    while(M>2*(N-1)) {
        per++;
        M-=2*(N-1);
    }
    ll ret=per*2*(A[N-1]-A[0]);
    num[0]-=per;
    num[N-1]-=per;
    for(i=1;i<=N-2;i++) num[i]-=2*per;
    
    if(num[0]==0 && num[N-1]==0) {
        l=N,r=0;
        for(i=1;i<=N-2;i++) if(num[i]) l=min(l,i), r=max(r,i);
        ret += A[r]-A[l];
    }
    else if(num[0]==0 && num[N-1]) {
        for(i=1;i<=N-2;i++) while(num[i]) {
            ret += A[N-1]-A[i];
            for(x=i;x<=N-2;x++) num[x]--;
        }
    }
    else if(num[0] && num[N-1]==0) {
        for(i=N-2;i>=1;i--) while(num[i]) {
            ret += A[i]-A[0];
            for(x=1;x<=i;x++) num[x]--;
        }
    }
    else if(num[0] && num[N-1]) {
        for(i=1;i<=N-2;i++) {
            if(num[i]!=2) {
                ret += A[i-1]-A[0];
                break;
            }
        }
        if(i==N-1) {
            FOR(i,N-1) if(A[i+1]-A[i] != A[1]-A[0]) return _P("-1\n");
            cout<< ret + 2*(A[N-1]-A[0])-(A[1]-A[0]) << endl;
            return;
        }
        
        ret += A[N-1]-A[0];
        for(i=N-2;i>=1;i--) {
            if(num[i]!=2) {
                ret += A[N-1]-A[i+1];
                break;
            }
        }
        
    }
    
    cout<<ret<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}