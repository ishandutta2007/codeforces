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

vector<int> Zalgo(string s) {
    vector<int> v(1,s.size());
    for(int i=1,l=-1,r=-1;i<s.size();i++) {
        if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
        else {
            l=i; r=(i>r)?i:(r+1);
            while(r<s.size() && s[r-i]==s[r]) r++;
            v.push_back((r--)-l);
        }
    }
    return v;
}

int N,M,L;
string P;
int Y[1010101];
int Y2[1010101];
ll mo=1000000007;


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    cin>>P;
    L=P.size();
    FOR(i,M) cin>>Y[i], Y2[--Y[i]]++;
    
    vector<int> V=Zalgo(P);
    
    FOR(i,M-1) if(Y[i+1]-Y[i]<L) {
        x=Y[i+1]-Y[i];
        if(V[x]!=L-x) return _P("0\n");
    }
    ll ret=1;
    x=-1;
    FOR(i,N) {
        if(Y2[i]) x=i+L;
        if(i>=x) ret=ret*26%mo;
    }
    cout<<ret<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}