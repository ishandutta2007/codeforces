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

int N,M;
ll L[100020],R[100020],T[100020];
ll Q[100020];
vector<pair<ll,ll> > QP;
ll PP[200200];
ll AS[200200],BS[200200],ret[200200];
vector<ll> S[200200],E[200200];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    FOR(i,M) cin>>L[i]>>R[i]>>T[i];
    FOR(i,N) cin>>Q[i], QP.push_back(make_pair(Q[i],i));
    sort(QP.begin(),QP.end());
    
    // compress
    map<ll,ll> UM;
    UM[0]=0;
    FOR(i,M) UM[L[i]]=UM[R[i]]=1;
    i=0;
    ITR(it,UM) it->second=i++, PP[it->second]=it->first;
    FOR(i,M) S[UM[L[i]]].push_back(T[i]),E[UM[R[i]]].push_back(T[i]);
    
    
    map<ll,int> CS;
    FOR(i,UM.size()) {
        FOR(j,E[i].size()) if(--CS[E[i][j]]==0) CS.erase(E[i][j]);
        FOR(j,S[i].size()) CS[S[i][j]]++;
        if(CS.size()) {
            ll ct=CS.begin()->first;
            x=lower_bound(QP.begin(),QP.end(),make_pair(ct-PP[i+1],0LL))-QP.begin();
            y=lower_bound(QP.begin(),QP.end(),make_pair(ct-PP[i],0LL))-QP.begin();
            AS[x]++; AS[y]--;
            BS[x]-=ct-PP[i+1], BS[y]+=ct-PP[i];
            
        }
    }
    
    ll aa=0,bb=0;
    FOR(i,N) aa+=AS[i], bb+=BS[i], ret[QP[i].second]=aa*QP[i].first+bb;
    FOR(i,N) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}