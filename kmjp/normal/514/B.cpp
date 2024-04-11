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

int N,XX,YY;
int X[1010],Y[1010];
set<pair<int,int> > S;
void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>XX>>YY;
    FOR(i,N) {
        cin>>X[i]>>Y[i];
        X[i]-=XX;
        Y[i]-=YY;
        ll g=__gcd(X[i],Y[i]);
        X[i]/=g;
        Y[i]/=g;
        if(X[i]<0) X[i]=-X[i],Y[i]=-Y[i];
        S.insert(make_pair(X[i],Y[i]));
    }
    cout<<S.size()<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}