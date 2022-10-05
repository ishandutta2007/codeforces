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

int N,M;

void solve() {
    int i,j,k,l,r; string s;
    
    ll a,b,x;
    
    cin>>N>>M;
    ll ret=0;
    for(a=M+1;a<=(N+1)/2;a++) {
        ll t=0;
        for(b=M+1;b<N+1-M && b<2*a;b++) {
            x=(2*a*a-a*b+3*N*b+3*b);
            l = N+1+M+1;
            r = 2*(N+1)-(M+1);
            if(x/(a+b)<l) t += r-l+1;
            else if(x/(a+b)<=r) t+=r-(x/(a+b));
        }
        ret += t*(2-(a==(N+1)/2 && N%2));
    }
    
    cout << ret*3 << endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}