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

int N,cent;
vector<pair<int,ll> > E[100001];
ll num[100001];
ll sc1[100001],sc2[100001],msc;

int M[100001];
int snum[100001];
vector<vector<int> > SS;
set<int> idord;
map<int,set<int> > numord;


void dfs1(int cur,int pre) {
    int i;
    num[cur]=1;
    FOR(i,E[cur].size()) {
        int tar=E[cur][i].first;
        if(tar!=pre) {
            dfs1(tar,cur);
            sc1[cur]+=sc1[tar]+num[tar]*E[cur][i].second;
            num[cur]+=num[tar];
        }
    }
}
void dfs2(int cur,int pre,ll csc) {
    int i;
    FOR(i,E[cur].size()) {
        int tar=E[cur][i].first;
        if(tar!=pre) dfs2(tar,cur,csc+sc1[cur]+(N-2*num[tar])*E[cur][i].second-sc1[tar]);
    }
    
    ll mav=N-num[cur];
    FOR(i,E[cur].size()) if(E[cur][i].first!=pre) mav=max(mav,num[E[cur][i].first]);
    if(mav<=N/2 && csc+sc1[cur]>msc) msc=csc+sc1[cur], cent=cur;
}
void dfs3(int cur,int pre,int id) {
    int i;
    M[cur]=id;
    FOR(i,E[cur].size()) if(E[cur][i].first != pre) dfs3(E[cur][i].first,cur,id);
}


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N-1) {
        cin>>x>>y>>j;
        E[x-1].push_back(make_pair(y-1,j));
        E[y-1].push_back(make_pair(x-1,j));
    }
    dfs1(0,-1);
    dfs2(0,-1,0);
    
    _P("%lld\n",2*msc);
    
    M[cent]=0;
    FOR(i,E[cent].size()) dfs3(E[cent][i].first,cent,i+1);
    SS.resize(E[cent].size()+1);
    
    for(i=N-1;i>=0;i--) SS[M[i]].push_back(i);
    FOR(j,SS.size()) snum[j]=SS[j].size()*2, idord.insert(SS[j].back()), numord[-snum[j]].insert(j);
    FOR(i,N) {
        //del old
        j=M[i];
        numord[-snum[j]].erase(j);
        if(numord[-snum[j]].empty()) numord.erase(-snum[j]);
        snum[j]--;
        if(SS[j].size()) numord[-snum[j]].insert(j);
        
        if(-numord.begin()->first>=(N-i) && *numord.begin()->second.begin()!=0) j=*numord.begin()->second.begin(); //largest
        else { //lexico lowest
            ITR(it,idord) if(M[*it]!=j || j==0) {
                j=M[*it];
                break;
            }
        }
        _P("%d ",SS[j].back()+1);
        //del
        numord[-snum[j]].erase(j);
        if(numord[-snum[j]].empty()) numord.erase(-snum[j]);
        idord.erase(SS[j].back());
        SS[j].pop_back();
        snum[j]--;
        if(SS[j].size()) idord.insert(SS[j].back()), numord[-snum[j]].insert(j);
        
        
    }
    _P("\n");
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}