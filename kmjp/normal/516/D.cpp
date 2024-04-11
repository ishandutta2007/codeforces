#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define Minu(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;
vector<pair<int,int> > E[101000];
pair<int,int> P[101000];
ll D[2][101000];
ll L,ma;
vector<pair<ll,int> > S;
int Minu[101000],ret;

ll dfs1(int cur,int pre) {
    int i;
    FOR(i,E[cur].size()) if(E[cur][i].first != pre) D[0][cur] = max(D[0][cur], dfs1(E[cur][i].first,cur)+E[cur][i].second);
    return D[0][cur];
}

void dfs2(int cur,int pre,ll tot) {
    int i;
    vector<pair<ll,int> > V;
    V.emplace_back(tot,cur);
    FOR(i,E[cur].size()) if(E[cur][i].first != pre) V.emplace_back(D[0][E[cur][i].first]+E[cur][i].second,E[cur][i].first);
    sort(V.begin(),V.end());
    reverse(V.begin(),V.end());
    FOR(i,E[cur].size()) if(E[cur][i].first != pre) {
        if(V[0].second==E[cur][i].first) dfs2(E[cur][i].first, cur, V[1].first+E[cur][i].second);
        else dfs2(E[cur][i].first, cur, V[0].first+E[cur][i].second);
    }
    D[1][cur]=V[0].first;
}

int dfs3(int cur,int pre) {
    ll ma=0;
    int tot=1;
    int i;
    
    S.push_back(make_pair(D[1][cur],cur));
    FOR(i,E[cur].size()) if(E[cur][i].first != pre) tot += dfs3(E[cur][i].first,cur);
    S.pop_back();
    tot -= Minu[cur];
    ret=max(ret,tot);
    
    vector<pair<ll,int> >::iterator it=lower_bound(S.begin(),S.end(),make_pair(D[1][cur]-L,0));
    if(it!=S.begin()) {
        it--;
        Minu[it->second]++;
    }
    
    
    
    return tot;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N-1) {
        cin>>x>>y>>r;
        E[x-1].emplace_back(y-1,r);
        E[y-1].emplace_back(x-1,r);
    }
    dfs1(0,-1);
    dfs2(0,-1,0);
    int piv=0;
    FOR(i,N) if(D[1][piv]>D[1][i]) piv=i;
    cin>>Q;
    while(Q--) {
        cin>>L;
        ret=0;
        ZERO(Minu);
        S.clear();
        dfs3(piv,-1);
        cout<<ret<<endl;
    }
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}