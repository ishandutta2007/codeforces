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

const int NV=1<<17;
int V[NV*2][60];
int N,Q;

int getval(int x,int y,int mo=0,int l=0,int r=NV,int k=1) {
    if(r<=x || y<=l) return 0;
    if(x<=l && r<=y) return V[k][mo];
    int a=getval(x,y,mo,l,(l+r)/2,k*2);
    int b=getval(x,y,(mo+a)%60,(l+r)/2,r,k*2+1);
    return a+b;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) {
        cin>>r;
        FOR(j,60) V[NV+i+1][j]=1+((j%r)==0);
    }
    for(i=NV-1;i>=0;i--) {
        FOR(j,60) V[i][j]=V[i*2][j]+V[i*2+1][(j+V[i*2][j])%60];
    }
    
    cin>>Q;
    while(Q--) {
        cin>>s>>x>>y;
        if(s[0]=='A') {
            cout<<getval(x,y)<<endl;
        }
        else {
            r=NV+x;
            FOR(j,60) V[r][j]=1+((j%y)==0);
            while(r>1) {
                r>>=1;
                FOR(j,60) V[r][j]=V[r*2][j]+V[r*2+1][(j+V[r*2][j])%60];
            }
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