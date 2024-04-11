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

int N,M;

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N>>M;
    
    vector<pair<int,int> > V;
    V.push_back(make_pair(0,0));    V.push_back(make_pair(1,0));    V.push_back(make_pair(0,1));
    V.push_back(make_pair(N,0));    V.push_back(make_pair(N-1,0));  V.push_back(make_pair(N,1));
    V.push_back(make_pair(0,M));    V.push_back(make_pair(1,M));    V.push_back(make_pair(0,M-1));
    V.push_back(make_pair(N,M));    V.push_back(make_pair(N-1,M));  V.push_back(make_pair(N,M-1));
    
    double ma=0;
    x=0;
    int a,b,c,d;
    FOR(a,V.size()) FOR(b,V.size()) FOR(c,V.size()) FOR(d,V.size()) {
        if(V[a]==V[b] || V[a]==V[c] || V[a]==V[d] || V[b]==V[c] || V[b]==V[d] || V[c]==V[d]) continue;
        if(V[a].first<0 || V[b].first<0 || V[c].first<0 || V[d].first<0) continue;
        if(V[a].second<0 || V[b].second<0 || V[c].second<0 || V[d].second<0) continue;
        if(V[a].first>N || V[b].first>N || V[c].first>N || V[d].first>N) continue;
        if(V[a].second>M || V[b].second>M || V[c].second>M || V[d].second>M) continue;
        double ret=sqrt((V[a].first-V[b].first)*(V[a].first-V[b].first)+(V[a].second-V[b].second)*(V[a].second-V[b].second));
        ret+=sqrt((V[c].first-V[b].first)*(V[c].first-V[b].first)+(V[c].second-V[b].second)*(V[c].second-V[b].second));
        ret+=sqrt((V[c].first-V[d].first)*(V[c].first-V[d].first)+(V[c].second-V[d].second)*(V[c].second-V[d].second));
        if(ret>ma) ma=ret,x=a*1000000+b*10000+c*100+d;
    }
    a=x/1000000;
    b=x/10000%100;
    c=x/100%100;
    d=x%100;
    return _P("%d %d\n%d %d\n%d %d\n%d %d\n",V[a].first,V[a].second,V[b].first,V[b].second,V[c].first,V[c].second,V[d].first,V[d].second);
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}