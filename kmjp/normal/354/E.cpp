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

int pat[100][6];
int pat2[5000][6];
int T;
ll N;
int val[7];

bool dfs(ll V,int d) {
    int i;
    if(d>=7) return false;
    if(V==0) {
        while(d<7) val[d++]=0;
        return true;
    }
    FOR(i,5) {
        int v=V%1000+i*1000;
        if(pat2[v][0]==-1 || V<v) continue;
        val[d]=v;
        if(dfs((V-v)/1000,d+1)) return true;
        val[d]=-1;
    }
    return false;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    MINUS(pat);
    MINUS(pat2);
    FOR(j,7) FOR(k,7) if(j+k<=6) FOR(l,6) {
        if(l<k) pat[j*4+k*7][l]=7;
        else if(l<k+j) pat[j*4+k*7][l]=4;
        else pat[j*4+k*7][l]=0;
    }
    
    FOR(i,50) FOR(j,50) FOR(k,50) if(pat[i][0]>=0&&pat[j][0]>=0&&pat[k][0]>=0) {
        if(pat2[i*100+j*10+k][0]>=0) continue;
        FOR(l,6) pat2[i*100+j*10+k][l]=pat[i][l]*100+pat[j][l]*10+pat[k][l];
    }
    
    cin>>T;
    while(T--) {
        cin>>N;
        MINUS(val);
        if(!dfs(N,0)) _P("-1\n");
        else {
            FOR(l,6) {
                ll v=pat2[val[6]][l]*1000000000000000000LL;
                v+=pat2[val[5]][l]*1000000000000000LL;
                v+=pat2[val[4]][l]*1000000000000LL;
                v+=pat2[val[3]][l]*1000000000LL;
                v+=pat2[val[2]][l]*1000000LL;
                v+=pat2[val[1]][l]*1000LL;
                v+=pat2[val[0]][l];
                _P("%lld ",v);
            }
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