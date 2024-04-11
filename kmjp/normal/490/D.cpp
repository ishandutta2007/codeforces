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

ll A[2],B[2];

map<int,int> S[4];
map<ll,pair<int,pair<ll,ll> > > M[2];

map<int,int> sp(ll v) {
    int sp2=0,sp3=0;
    map<int,int> s;
    
    while(v) {
        
        ll t=v;
        sp2=0;
        s[t]=sp2+sp3;
        while(t%2==0) t/=2,sp2++, s[t]=sp2+sp3;
        if(v%3!=0) break;
        sp3++;
        v=v*2/3;
    }
    
    return s;
    
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>A[0]>>B[0];
    cin>>A[1]>>B[1];
    
    S[0]=sp(A[0]);
    S[1]=sp(B[0]);
    
    ITR(it,S[0]) ITR(it2,S[1]) M[0][1LL*it->first*it2->first] = make_pair(it->second+it2->second, make_pair(it->first,it2->first));
    S[2]=sp(A[1]);
    S[3]=sp(B[1]);
    ITR(it,S[2]) ITR(it2,S[3]) M[1][1LL*it->first*it2->first] = make_pair(it->second+it2->second, make_pair(it->first,it2->first));
    
    int mi=100000;
    ll v;
    
    ITR(it,M[0]) {
        if(M[1].count(it->first)==0) continue;
        i=it->second.first + M[1][it->first].first;
        if(i < mi) mi=i, v=it->first;
    }
    
    if(mi==100000) {
        _P("-1\n");
    }
    else {
        _P("%d\n",mi);
        _P("%lld %lld\n",M[0][v].second.first,M[0][v].second.second);
        _P("%lld %lld\n",M[1][v].second.first,M[1][v].second.second);
    }
    
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}