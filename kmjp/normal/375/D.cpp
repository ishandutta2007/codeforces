#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------


int N,M;
int ti=0;
int C[100010],num[100010];
vector<int> E[100010];
vector<pair<int,int> > Q[100010];
int L[100010],R[100010],C2[100010];
int res[100010];
map<int,int> NM[100010];
vector<int> NV[100010];

void dfs(int cur,int pre) {
    int i,j;
    int mi=-1,ma=0;
    
    L[cur]=ti++;
    FOR(i,E[cur].size()) {
        int tar=E[cur][i];
        if(pre!=tar) {
            dfs(tar,cur);
            if(NM[tar].size()>ma) ma=NM[tar].size(),mi=tar;
        }
    }
    R[cur]=ti-1;
    num[cur]=ti-L[cur];
    
    NM[cur][C[cur]]=1;
    NV[cur].push_back(1);
    
    if(mi!=-1) {
        swap(NM[cur],NM[mi]);
        swap(NV[cur],NV[mi]);
        FOR(i,E[cur].size()) {
            int tar=E[cur][i];
            if(pre==tar) continue;
            ITR(it,NM[tar]) {
                for(j=NM[cur][it->first]+1;j<=NM[cur][it->first]+it->second;j++) {
                    if(j>NV[cur].size()) NV[cur].push_back(1);
                    else NV[cur][j-1]++;
                }
                NM[cur][it->first] += it->second;
            }
        }
    }
    
    FOR(i,Q[cur].size()) {
        if(NV[cur].size() >= Q[cur][i].first)
            res[Q[cur][i].second] = NV[cur][Q[cur][i].first-1];
    }
    
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M;
    FOR(i,N) cin>>C[i];
    FOR(i,N-1) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }
    FOR(i,M) {
        cin>>x>>y;
        Q[x-1].push_back(make_pair(y,i));
    }
    FOR(i,N) sort(Q[i].begin(),Q[i].end());
    dfs(0,-1);
    FOR(i,M) _P("%d\n",res[i]);
    
    
}


int main(int argc,char** argv){
    string s;
    ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}