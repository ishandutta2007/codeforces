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
ll L[12000],R[12000];

ll dodo(ll x,ll y) {
    if(x==y) return y;
    int i;
    for(i=62;i>=1;i--) {
        if((x&(1LL<<i))!=(y&(1LL<<i))) {
            if((y&((1LL<<i)-1))==((1LL<<i)-1)) return y;
            return x|((1LL<<i)-1);
        }
    }
    return y;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) {
        cin>>L[i]>>R[i];
        cout << dodo(L[i],R[i]) << endl;
    }
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}