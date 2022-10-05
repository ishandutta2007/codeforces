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


ll N,C;
int A[101000];
ll ret;

int ok(int V) {
    int i,j,k;
    map<int,int> M;
    
    if(V<N/2) {
        FOR(i,N) {
            if(i<=V) M[A[i]]++;
            else if(N-1-i<=V) {
                if(M[A[i]]--==0) return false;
            }
            else if(A[i]!=A[N-i-1]) return false;
        }
        return true;
    }
    else {
        FOR(i,N) {
            if(i<=V) M[A[i]]++;
            else if(M[A[i]]--==0) return false;
        }
        j=0;
        ITR(it,M) j+=it->second%2;
        return j==N%2;
    }
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>A[i];
    
    FOR(C,N) if(A[C]!=A[N-1-C]) break;
    if(C==N) {
        cout<<N*(N+1)/2<<endl;
        return;
    }
    N-=2*C;
    FOR(i,N) A[i]=A[i+C];
    if(!ok(N-1)) return _P("0\n");
    ret += (C+1)*(C+1);
    FOR(i,2) {
        x=0;
        for(j=20;j>=0;j--) if(x+(1<<j)<=N-2 && !ok(x+(1<<j))) x+=1<<j;
        //if(N==90765) _P("%d %d %d\n",x,ok(x),ok(x+1));
        ret += (C+1)*(N-x-2);
        reverse(A,A+N);
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