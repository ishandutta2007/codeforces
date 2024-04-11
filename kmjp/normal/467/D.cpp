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
string W[200000];
map<string,int> mp;
string F[200000],T[200000];
ll sc[400000];

vector<int> E[300000];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) {
        cin>>W[i];
        ITR(it,W[i]) *it=tolower(*it);
        mp[W[i]]=0;
    }
    cin>>M;
    FOR(i,M) {
        cin>>F[i]>>T[i];
        ITR(it,F[i]) *it=tolower(*it);
        ITR(it,T[i]) *it=tolower(*it);
        mp[F[i]]=mp[T[i]]=0;
    }
    i=0;
    ITR(it,mp) {
        it->second=i;
        sc[i]=(1LL<<40)*count(it->first.begin(),it->first.end(),'r')+it->first.size();
        i++;
    }
    FOR(i,M) E[mp[T[i]]].push_back(mp[F[i]]);
    priority_queue<pair<ll,int> > Q;
    FOR(i,mp.size()) Q.push(make_pair(-sc[i],i));
    while(!Q.empty()) {
        ll s=-Q.top().first;
        int k=Q.top().second;
        Q.pop();
        if(s!=sc[k]) continue;
        FOR(i,E[k].size()) {
            int tar=E[k][i];
            if(sc[tar]>sc[k]) {
                sc[tar]=sc[k];
                Q.push(make_pair(-sc[tar],tar));
            }
        }
    }
    
    ll tr=0,tl=0;
    FOR(i,N) {
        ll s=sc[mp[W[i]]];
        tr+=s>>40;
        tl+=s-((s>>40)<<40);
    }
    _P("%lld %lld\n",tr,tl);
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}