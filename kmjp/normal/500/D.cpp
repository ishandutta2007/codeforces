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

int N,Q;
ll P[4][1020000];

int A[102000],B[102000],L[102000],NN[102000];
vector<pair<int,int> > E[102000];
vector<int> num[102000];
double tot;

int dfs(int cur,int pre) {
    int i,j=-1;
    int n=1;
    num[cur].resize(E[cur].size());
    
    FOR(i,E[cur].size()) {
        int tar=E[cur][i].first;
        if(pre==tar) j=i;
        else {
            n+=num[cur][i]=dfs(tar,cur);
            NN[E[cur][i].second]=num[cur][i];
        }
    }
    if(j>=0) {
        num[cur][j]=N-n;
        NN[E[cur][j].second]=N-n;
    }
    return n;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    cin>>N;
    
    FOR(i,102000) {
        P[0][i]=1;
        P[1][i]=i;
        P[2][i]=1LL*i*(i-1)/2;
        P[3][i]=1LL*i*(i-1)*(i-2)/6;
    }
    
    FOR(i,N-1) {
        cin>>A[i]>>B[i]>>L[i];
        A[i]--,B[i]--;
        E[A[i]].push_back(make_pair(B[i],i));
        E[B[i]].push_back(make_pair(A[i],i));
    }
    dfs(0,-1);
    
    double tot=0;
    FOR(i,N-1) {
        ll n=NN[i];
        tot+=L[i]*1.0*(P[1][n]*P[2][N-n]*2+P[2][n]*P[1][N-n]*2);
    }
    cin>>Q;
    while(Q--) {
        cin>>x>>y;
        x--;
        ll n=NN[x];
        tot-=(L[x]-y)*1.0*(P[1][n]*P[2][N-n]*2+P[2][n]*P[1][N-n]*2);
        L[x]=y;
        _P("%.12lf\n",tot/P[3][N]);
    }
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}