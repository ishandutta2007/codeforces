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

int N,M,K;
vector<pair<int,int> > P;

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M>>K;
    FOR(y,N) {
        FOR(x,M) {
            if(y%2==0) P.push_back(make_pair(y+1,x+1));
            else P.push_back(make_pair(y+1,M-x));
        }
    }
    FOR(i,K-1) {
        _P("%d %d %d %d %d\n",2,P[i*2].first,P[i*2].second,P[i*2+1].first,P[i*2+1].second);
    }
    x=(K-1)*2;
    _P("%d ",N*M-x);
    while(x<N*M) _P("%d %d ",P[x].first,P[x].second), x++;
    _P("\n");
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}