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
int A[100500];
int L[6000],R[6000];
double P[6000];
int par[5002];
vector<pair<int,int> > C[100020];
int ma[5002];
map<int,double> res[5002];

map<int,double> merge(map<int,double> m1,map<int,double> m2) {
    map<int,double> res;
    ITR(it1,m1) ITR(it2,m2) if(it1->second*it2->second)
        res[max(it1->first,it2->first)] += it1->second*it2->second;
    return res;
}

int dfs(int cur,int le) {
    int x=0;
    sort(ALL(C[cur]));
    ma[cur]=-1;
    
    for(;le<=R[cur];le++) {
        while(x<C[cur].size() && C[cur][x].first==le) le=dfs(C[cur][x].second,le), x++;
        if(le>R[cur]) break;
        ma[cur]=max(ma[cur],A[le]);
    }
    
    map<int,double> tmp;
    tmp[ma[cur]]=1.0;
    FOR(x,C[cur].size()) tmp=merge(tmp,res[C[cur][x].second]);
    ITR(it,tmp) {
        res[cur][it->first+1] += it->second*P[cur];
        res[cur][it->first] += it->second*(1-P[cur]);
    }
    return le;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>Q;
    FOR(i,N) cin>>A[i];
    
    FOR(i,Q) cin>>L[i+1]>>R[i+1]>>P[i+1], L[i+1]--,R[i+1]--;
    Q++;
    L[0]=0,R[0]=N-1;
    
    FOR(i,Q) {
        par[i]=-1;
        int w=N+1;
        FOR(j,Q) if(i!=j) {
            if(L[j]==L[i]&&R[i]==R[j]) {
                if(j<i) par[i]=j, w=R[i]-L[i];
            }
            else if(L[j]<=L[i]&&R[i]<=R[j]&&R[j]-L[j]<=w) par[i]=j, w=R[j]-L[j];
        }
        if(par[i]!=-1) C[par[i]].push_back(make_pair(L[i],i));
    }
    
    dfs(0,0);
    double ret=0;
    ITR(it,res[0]) ret += it->first*it->second;
    _P("%.12lf\n",ret);
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}