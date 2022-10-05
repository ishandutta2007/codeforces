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
#include <sys/time.h>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
void _fill_ll(ll* p,ll val,int rep) {int i; FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define MINUSL(a) _fill_ll((ll*)a,-1LL,sizeof(a)/8)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N,M;
vector<int> E[100001];
int D[100001],P[12][100001],TD[100001];

void dfs(int cur,int pre) {
    int j=-1;
    TD[cur]=D[cur]=(pre==-1)?0:(D[pre]+1);
    P[0][cur]=pre;
    for(int i=0;i<E[cur].size();i++) {
        int tar=E[cur][i];
        if(tar!=pre) dfs(tar,cur);
    }
}


int len(int a,int b){
    int l=0,i,oa=a,ob=b;
    if(D[a]<D[b]) swap(a,b);
    while(D[a]>D[b]) {
        i=0;
        while(D[a]-D[b]>=(1<<(i+1)) && i<=9) i++;
        l+=1<<i;
        a=P[i][a];
    }
        
    while(a!=b) {
        for(i=10;i>0;i--) if(P[i][a]!=P[i][b]) break;
        l+=2<<i,a=P[i][a],b=P[i][b];
    }
    return l;
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M;
    FOR(i,N-1) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }
    dfs(0,-1);
    FOR(j,10) FOR(i,N) P[j+1][i]=(P[j][i]==-1)?-1:P[j][P[j][i]];
    
    set<int> NR;
    
    FOR(i,M) {
        cin>>x>>y;
        if(x==1) {
            TD[y-1]=0;
            NR.insert(y-1);
                
            if(NR.size()>100) {
                queue<int> Q;
                ITR(it,NR) Q.push(*it);
                NR.clear();
                while(!Q.empty()) {
                    k=Q.front();
                    Q.pop();
                    FOR(j,E[k].size()) {
                        int tar=E[k][j];
                        if(TD[k]+1<TD[tar]) {
                            TD[tar] = TD[k]+1;
                            Q.push(tar);
                        }
                    }
                }
            }
        }
        else {
            int x=TD[y-1];
            if(x!=0) ITR(it,NR) x=min(x,len(y-1,*it));
            _P("%d\n",x);
        }
    }
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}