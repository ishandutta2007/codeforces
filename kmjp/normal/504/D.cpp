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
ll V[2001][70];
ll sel[2001][70];
int bm[2002];

void conv(int cur,string s) {
    int i,j;
    ll v[105]={};
    FOR(i,100) {
        v[i]+=(s[i*6+5]-'0')*100000;
        v[i]+=(s[i*6+4]-'0')*10000;
        v[i]+=(s[i*6+3]-'0')*1000;
        v[i]+=(s[i*6+2]-'0')*100;
        v[i]+=(s[i*6+1]-'0')*10;
        v[i]+=(s[i*6+0]-'0')*1;
    }
    FOR(i,2000) {
        V[cur][i/32] |= (v[0]&1)<<(i%32);
        FOR(j,100) v[j]=(v[j]>>1) + ((v[j+1]&1)*500000);
    }
}


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    MINUS(bm);
    
    cin>>N;
    FOR(i,N) {
        cin>>s;
        
        reverse(s.begin(),s.end());
        s=s+string(601,'0');
        conv(i,s.substr(0,600));
        sel[i][i/32]=1LL<<(i%32);
        
        for(j=1999;j>=0;j--) if(V[i][j/32]&(1LL<<(j%32))) {
            if(bm[j]>=0) {
                FOR(x,70) V[i][x] ^= V[bm[j]][x];
                FOR(x,70) sel[i][x] ^= sel[bm[j]][x];
            }
            else {
                _P("0\n");
                bm[j]=i;
                break;
            }
        }
        
        if(j==-1) {
            y=0;
            FOR(x,70) y+=__builtin_popcountll(sel[i][x]);
            _P("%d",y-1);
            FOR(x,i) if(sel[i][x/32]&(1LL<<(x%32))) _P(" %d",x);
            _P("\n");
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