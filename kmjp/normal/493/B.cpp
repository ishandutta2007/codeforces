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
vector<ll> V[2];
ll T;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) {
        cin>>x;
        T+=x;
        if(x<0) V[0].push_back(x);
        if(x>0) V[1].push_back(-x);
    }
    if(T>0) cout << "first" << endl;
    else if(T<0) cout << "second" << endl;
    else {
        if(V[0]>V[1]) {
            cout << "first" << endl;
            return;
        }
        if(V[0]<V[1]) {
            cout << "second" << endl;
            return;
        }
        if(x>0) cout << "first" << endl;
        else cout << "second" << endl;
    }
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}