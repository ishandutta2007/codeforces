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

string A,B;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>A>>B;
    FOR(i,110000) s+='0';
    A=s+A;
    B=s+B;
    A=A.substr(A.size()-100005);
    B=B.substr(B.size()-100005);
    FOR(i,100005) A[i]-='0',B[i]-='0';
    FOR(i,100003) {
        int dif=A[i]-B[i];
        if(dif>4) return _P(">\n");
        if(dif<-4) return _P("<\n");
        A[i+1]+=dif;
        A[i+2]+=dif;
    }
    double aa=(sqrt(5)+1)/2*A[100003]+A[100004];
    double bb=(sqrt(5)+1)/2*B[100003]+B[100004];
    if(aa>bb) return _P(">\n");
    if(aa<bb) return _P("<\n");
    _P("=\n");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}