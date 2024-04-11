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

int M,K,P;
vector<int> E[100001];
int D[100001],DN[100001],MD;
vector<int> VD;
ll C[100002];


void dfs(int cur,int pre) {
    int i;
    if(pre!=-1) D[cur]=D[pre]+1;
    MD=max(MD,D[cur]+1);
    DN[D[cur]]++;
    FOR(i,E[cur].size()) if(E[cur][i]!=pre) dfs(E[cur][i],cur);
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>M>>K>>P;
    FOR(i,M-1) {
        cin>>x>>y;
        E[x-1].push_back(y-1);
        E[y-1].push_back(x-1);
    }
    dfs(0,-1);
    for(i=1;i<MD;i++) FOR(j,DN[i]) VD.push_back(i);
    for(i=VD.size()-1;i>=0;i--) C[i]=C[i+1]+100000LL-VD[i];
    
    int ma=min(1,K);
    FOR(i,VD.size()) {
        if(i<VD.size()-1 && VD[i]==VD[i+1]) continue;
        int L=max(0,i-(K-1)),R=i;
        while(L<R) {
            ll po=(L+R)/2;
            ll cost=C[po]-C[i+1]-(100000LL-VD[i])*(i+1-po);
            if(cost<=P) R=po;
            else L=po+1;
        }
        ma=max(ma,i-L+1);
    }
    
    cout << ma << endl;
    
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}