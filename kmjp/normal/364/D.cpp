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
ll A[1010000];
ll ma;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>A[i];
    sort(A,A+N);
    
    srand(time(NULL)+A[0]);
    FOR(i,10) {
        j=(rand()*1007LL+rand()+rand()*13LL)%N;
        vector<ll> V;
        FOR(k,N) V.push_back(__gcd(A[j],A[k]));
        vector<pair<ll,int> > V2;
        sort(ALL(V));
        FOR(k,N) {
            if(V2.empty() || V2.back().first!=V[k]) V2.push_back(make_pair(V[k],1));
            else V2.back().second++;
        }
        
        ITR(it,V2) if(ma<it->first) {
            x=0;
            for(vector<pair<ll,int> >::iterator it2=it;it2!=V2.end()&&x<(N+1)/2;it2++)
                if(it2->first%it->first==0) x+=it2->second;
            if(x>=(N+1)/2) ma=it->first;
        }
    }
    cout<<ma<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}