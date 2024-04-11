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

int N,T;
ll H[100050],L[100050],R[100050],F[100050];
vector<pair<ll,int> > V;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>T;
    FOR(i,N) cin>>H[i]>>L[i]>>R[i];
    H[N]=T,L[N]=(-1<<30)+1,R[N]=(1<<30)-1;
    H[N+1]=0,L[N+1]=-1<<30,R[N+1]=1<<30,F[N+1]=1LL<<31;
    N+=2;
    FOR(i,N) V.push_back(make_pair(H[i],i));
    sort(V.begin(),V.end());
    
    set<pair<ll,int> > S;
    set<pair<ll,int> >::iterator sit,cur,p,n;
    S.insert(make_pair(L[N-1],N-1));
    S.insert(make_pair(R[N-1],N-1));
    for(i=1;i<N;i++) {
        j=V[i].second;
        cur=sit=S.lower_bound(make_pair(L[j],j));
        for(cur--;cur!=S.end() && cur->first < R[j];cur++) {
            p=n=cur;
            if(p!=S.begin()) p--;
            if(n!=S.end()) n++;
            x=p->second,y=n->second,r=cur->second;
            if(H[x]>H[r] && min(R[j],R[x])-max(L[j],L[x])>0 && min(R[x],R[r])-max(L[x],L[r])>0) continue;
            if(H[y]>H[r] && min(R[j],R[y])-max(L[j],L[y])>0 && min(R[y],R[r])-max(L[y],L[r])>0) continue;
            F[j]=max(F[j],min(F[r],min(R[j],R[r])-max(L[j],L[r])));
        }
        p=cur;
        p--;
        x=p->second;
        S.erase(sit,cur);
        if(cur->first>R[j]) S.insert(make_pair(R[j],x));
        S.insert(make_pair(L[j],j));
    }
    cout<<F[N-2]<<endl;
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}