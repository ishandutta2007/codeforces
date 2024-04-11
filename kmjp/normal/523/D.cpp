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

int N,K;
ll S[506000],M[505000];

void solve() {
    int i,j,k,l,r,x,y; string s;
    multiset<ll> SS;
    
    cin>>N>>K;
    FOR(i,N) {
        cin>>S[i]>>M[i];
        
        while(SS.size() && *SS.begin()<=S[i]) SS.erase(SS.begin());
        
        if(SS.size()<K) {
            cout<<S[i]+M[i]<<endl;
            SS.insert(S[i]+M[i]);
        }
        else {
            cout<<*SS.begin()+M[i]<<endl;
            SS.insert(*SS.begin()+M[i]);
            SS.erase(SS.begin());
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