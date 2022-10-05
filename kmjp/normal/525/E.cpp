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

int N,K;
ll S,A[40];
ll B[100];

map<ll,ll> M[2][30];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>K>>S;
    FOR(i,N) cin>>A[i];
    B[0]=1;
    FOR(i,20) {
        B[i+1]=B[i]*(i+1);
        if(B[i]==-1 || B[i+1]>10000000000000000LL) B[i+1]=-1;
    }
    
    M[0][0][0]=M[1][0][0]=1;
    FOR(i,N) {
        int id=i<12;
        map<ll,ll> tmp[16];
        FOR(x,15) tmp[x]=M[id][x];
        FOR(x,15) {
            FORR(r,tmp[x]) {
                M[id][x][r.first+A[i]] += r.second;
                if(A[i]<=18 && r.first+B[A[i]]<=S) M[id][x+1][r.first+B[A[i]]] += r.second;
            }
        }
    }
    
    ll ret=0;
    FOR(x,15) FOR(y,15) if(x+y<=K) {
        FORR(r,M[0][x]) ret += r.second * M[1][y][S-r.first];
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