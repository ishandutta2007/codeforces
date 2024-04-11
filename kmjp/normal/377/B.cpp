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
ll CC;
pair<ll,ll> A[100010];
pair<ll,pair<ll,int> > P[100010];
int res[100010];

int okok(ll D) {
    ll LC=CC;
    int ll=M-1,k=N-1,i;
    set<pair<int,int> > S;
    
    while(ll>=0) {
        while(k>=0 && P[k].first>=A[ll].first) {
            S.insert(make_pair(P[k].second.first,P[k].second.second));
            k--;
        }
        if(S.empty()) return 0;
        
        
        LC-=S.begin()->first;
        int ind=S.begin()->second+1;
        if(LC<0) return 0;
        S.erase(S.begin());
        FOR(i,D) {
            res[A[ll].second] = ind;
            if(--ll<0) break;
        }
        
    }
    return 1;
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M>>CC;
    FOR(i,M) {
        cin>>A[i].first;
        A[i].second=i;
    }
    FOR(i,N) cin>>P[i].first;
    FOR(i,N) cin>>P[i].second.first;
    FOR(i,N) P[i].second.second = i;
    sort(A,A+M);
    sort(P,P+N);
    
    if(okok(N+1)==0) return _P("NO\n");
    
    ll L=1,R=N+1;
    FOR(i,30) {
        ll P=(L+R)/2;
        if(okok(P)) R=P;
        else L=P+1;
    }
    L=max(1LL,L-2);
    while(okok(L)==0) L++;
    _P("YES\n");
    FOR(i,M) _P("%d ",res[i]);
    _P("\n");
    
}


int main(int argc,char** argv){
    string s;
    ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}