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

ll N,M,D;
pair<ll,int> PP[500];

template<class V>
void slidemin(vector<V>& inin, vector<V>& ouout,int num) {
    deque<V> deq;
    int i;
    
    // this impl stor onlu N-(num-1) entries
    ouout.clear();
    FOR(i,inin.size()) {
        while(!deq.empty() && inin[deq.back()]>=inin[i]) deq.pop_back();
        deq.push_back(i);
        if(i>=num-1) ouout.push_back(inin[deq.front()]);
        if(!deq.empty() && deq.front()==i-num+1) deq.pop_front();
    }
}

void solve() {
    int f,i,j,k,l,x,y;
    ll tot=0,tt;
    
    cin>>N>>M>>D;
    FOR(i,M) {
        cin>>PP[i].second>>tt>>PP[i].first;
        PP[i].second--;
        tot+=tt;
    }
    sort(PP,PP+M);
    
    vector<ll> aa,bb,cc;
    FOR(i,N) aa.push_back(0);
    
    j=1;
    FOR(i,M) {
        x=(int)min((PP[i].first-j)*D,(ll)N-1);
        cc.clear();
        FOR(y,x) cc.push_back(1LL<<50);
        FOR(y,N) cc.push_back(aa[y]);
        FOR(y,x) cc.push_back(1LL<<50);
        
        slidemin<ll>(cc,bb,1+2*x);
        cc.resize(N);
        FOR(y,N) cc[y]=bb[y] + abs(PP[i].second-y);
        swap(aa,cc);
        j=PP[i].first;
    }
    sort(aa.begin(),aa.end());
    
    cout << tot-aa[0] << endl;
    
}


int main(int argc,char** argv){
    string s;
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}