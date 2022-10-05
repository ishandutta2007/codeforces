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
ll X,Y,A[100200];

ll num(ll tim) {
    return tim/X + tim/Y;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>X>>Y;
    ll g=__gcd(X,Y);
    X/=g;
    Y/=g;
    
    while(N--) {
        cin>>r;
        
        r %= X+Y;
        if(r==0 || r==X+Y-1) cout<<"Both"<<endl;
        else {
            ll tim=0,tim2=0;
            for(i=39;i>=0;i--) if(num(tim+(1LL<<i))<=r-1) tim +=(1LL<<i);
            for(i=39;i>=0;i--) if(num(tim2+(1LL<<i))<=r) tim2 +=(1LL<<i);
            
            if(tim/Y!=tim2/Y) cout<<"Vanya"<<endl;
            else cout<<"Vova"<<endl;
            
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