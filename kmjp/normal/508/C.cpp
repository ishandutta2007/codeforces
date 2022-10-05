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

int M,T,R;
int W[400];
int on[800];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>M>>T>>R;
    FOR(i,M) {
        cin>>W[i];
        y=R;
        for(x=W[i];x>W[i]-T;x--) if(on[x+400]) y--;
        if(y<=0) continue;
        for(x=W[i];x>W[i]-T && y>0;x--) if(on[x+400]==0) on[x+400]=1, y--;
        if(y) return _P("-1\n");
    }
    _P("%d\n",count(on,on+800,1));
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}