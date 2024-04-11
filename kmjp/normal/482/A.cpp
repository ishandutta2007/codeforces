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

ll N,K;
int LB,UB;
void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N>>K;
    if(K==0) {
        FOR(i,N) _P("%d ",i+1);
        _P("\n");
        return;
    }
    else {
        LB=1;UB=N;
        FOR(i,K) {
            if(i%2==0) _P("%d ",LB++);
            else _P("%d ",UB--);
        }
        if(K%2==0) {
            for(i=UB;i>=LB;i--) _P("%d ",i);
        }
        else {
            for(i=LB;i<=UB;i++) _P("%d ",i);
        }
        _P("\n");
        
    }
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}