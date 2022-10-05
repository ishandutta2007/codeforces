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

string S;
int L;
double revsum[505000];
double revsum2[505000];

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>S;
    L=S.size();
    
    double ret=0;
    for(i=1;i<=500000;i++) revsum[i]=revsum[i-1]+1.0/i,revsum2[i]=revsum2[i-1]+revsum[i];
    
    FOR(i,L) {
        if(strchr("IEAOUY",S[i])) {
            x=max(i+1,L-i);
            ret += revsum2[L]-revsum2[L-x]-revsum2[x-1];
        }
    }
    _P("%.12lf\n",ret);
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}