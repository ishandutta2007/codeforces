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

ll C,HR,HB,WR,WB;
ll ma;

void solve() {
    int i,j,k,l,x,y; string s;
    ll r,b;
    
    cin>>C>>HR>>HB>>WR>>WB;
    FOR(i,2) {
        if(WR>=1000) {
            FOR(r,C/WR+1) ma=max(ma,r*HR+(C-r*WR)/WB*HB);
            cout<<ma<<endl;
            return;
        }
        swap(HR,HB), swap(WR,WB);
    }
    
    ll lcm=min(C,WB*WR/__gcd(WB,WR));
    FOR(r,lcm/WR+1) ma=max(ma,r*HR+(C-r*WR)/WB*HB);
    FOR(b,lcm/WB+1) ma=max(ma,b*HB+(C-b*WB)/WR*HR);
    
    cout<<ma<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}