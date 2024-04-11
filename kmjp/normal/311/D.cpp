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

int N,Q;
int tc[100002];
ll A[50][100002],S[50][100002];
ll mo=95542721;
map<int,int> M;

void build() {
    M[0]=M[N+1]=0;
    int cur=0,i,j;
    map<int,int>::iterator mit=M.begin();
    mit++;
    
    FOR(i,N) {
        if(mit->first==i+1) cur+=mit->second, mit++;
        tc[i+1]+=cur;
        FOR(j,48) S[j][i+1]=(S[j][i]+A[(j+tc[i+1])%48][i+1])%mo;
    }
    M.clear();
    M[0]=M[N+1]=0;
}

ll dodo(int id){
    int cur=0;
    map<int,int>::iterator mit=M.begin();
    ll ret=0;
    
    while(mit->first<=id) {
        int pre=mit->first;
        cur+=mit->second;
        mit++;
        if(pre>=0) ret += S[cur%48][min(id,mit->first-1)]-S[cur%48][pre-1];
    }
    
    return ret;
}

void solve() {
    int i,j,k,l,r; string s;
    
    cin>>N;
    FOR(i,N) {
        cin>>A[0][i+1];
        A[0][i+1]%=mo;
        FOR(j,48) A[j+1][i+1]=A[j][i+1]*A[j][i+1]%mo*A[j][i+1]%mo;
    }
    build();
    
    cin>>Q;
    while(Q--) {
        cin>>i>>l>>r;
        if(i==1) {
            cout<< ((dodo(r)-dodo(l-1))%mo+mo)%mo << endl;
        }
        else {
            M[l]++;
            M[r+1]--;
            if(M.size()>5000) build();
        }
    }
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}