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

int H[2],A[2],D[2];
int h,a,d;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>H[0]>>A[0]>>D[0];
    cin>>H[1]>>A[1]>>D[1];
    cin>>h>>a>>d;
    
    int mi=1<<29;
    FOR(x,201) FOR(y,201) {
        int at=A[0]+x-D[1];
        int dm=A[1]-(D[0]+y);
        if(at<=0) continue;
        
        if(dm<=0) mi=min(mi,x*a+y*d);
        else {
            int mt=(H[1]+at-1)/at;
            int nh=mt*dm+1;
            mi=min(mi,x*a+y*d+h*max(0,nh-H[0]));
        }
        
    }
    
    cout<<mi<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}