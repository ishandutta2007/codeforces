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

int N;
int C[1001],P[1001];
int K;
vector<pair<int,int> > PP;
vector<pair<int,int> > T;
int sit[1001],done[1001];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N;
    FOR(i,N) {
        cin>>C[i]>>P[i];
        PP.push_back(make_pair(P[i],i));
    }
    
    sort(PP.begin(),PP.end());
    cin>>K;
    FOR(i,K) {
        cin>>x;
        T.push_back(make_pair(x,i));
    }
    sort(T.begin(),T.end());
    reverse(PP.begin(),PP.end());
    
    MINUS(sit);
    int ma=0,tot=0;
    FOR(i,N) {
        FOR(j,K) if(done[j]==0) {
            if(C[PP[i].second]<=T[j].first) break;
        }
        if(j<K) {
            done[j]=1;
            ma++;
            tot+=PP[i].first;
            sit[PP[i].second]=T[j].second;
        }
    }
    
    _P("%d %d\n",ma,tot);
    FOR(i,N) if(sit[i]>=0) _P("%d %d\n",i+1,sit[i]+1);
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}