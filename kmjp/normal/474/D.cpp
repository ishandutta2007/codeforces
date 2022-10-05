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

int T,K;
ll num[100300];
ll R[100300];
ll mo=1000000007;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>T>>K;
    FOR(i,K) num[i]=1;
    for(i=K;i<=100000;i++) num[i]=(num[i-1]+num[i-K])%mo;
    
    FOR(i,100020) R[i+1]=(R[i]+num[i])%mo;
    
    FOR(i,T) {
        cin>>x>>y;
        ll tot=R[y+1]-R[x];
        cout << ((tot%mo)+mo)%mo << endl;
    }
}



int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}