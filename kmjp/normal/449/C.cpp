#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
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
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N;

const int prime_max = 1000000;
int NP,prime[100000],divp[prime_max];
vector<int> E[100001];
vector<pair<int,int> > V;
int vis2[100001];

void cprime() {
    int i,j;
    for(i=2;i<prime_max;i++) if(divp[i]==0) {
        prime[NP++]=i;
        for(j=i;j<prime_max;j+=i) divp[j]=i;
    }
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    
    cprime();
    for(i=2;i<=N;i++) if(i%2) E[divp[i]].push_back(i);
    
    for(i=3;i<=N;i++) if(E[i].size()) {
        for(j=0;j+1<E[i].size();j+=2) V.push_back(make_pair(E[i][E[i].size()-j-1],E[i][E[i].size()-j-2]));
        if(E[i].size()%2 && 2*i<=N) V.push_back(make_pair(i,2*i)),vis2[i*2]=1;
    }
    for(i=2;i<=N;i++) if(i%2==0 && vis2[i]==0) E[2].push_back(i);
    for(j=0;j+1<E[2].size();j+=2) V.push_back(make_pair(E[2][j],E[2][j+1]));
    cout << V.size() << endl;
    ITR(it,V) cout << it->first << " "  << it->second << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}