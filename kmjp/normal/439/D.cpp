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
vector<int> A,B;
ll SA[100002],SB[100002];
set<int> C;

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M;
    FOR(i,N) cin>>x,A.push_back(x),C.insert(x);
    FOR(i,M) cin>>x,B.push_back(x),C.insert(x);
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    if(B[M-1]<=A[0]) return _P("0\n");
    FOR(i,N) SA[i+1]=SA[i]+A[i];
    FOR(i,M) SB[i+1]=SB[i]+B[i];
    
    ll ret=1LL<<60;
    ITR(it,C) {
        int tv=*it;
        ll la=0,lb=0;
        vector<int>::iterator ita=lower_bound(A.begin(),A.end(),tv);
        int ida=ita-A.begin();
        if(ida>0) la = ida*(ll)tv-SA[ida];
        
        vector<int>::iterator itb=lower_bound(B.begin(),B.end(),tv);
        int idb=itb-B.begin();
        if(idb<M) lb = (SB[M]-SB[idb])-(M-idb)*(ll)tv;
        ret=min(ret,la+lb);
    }
    cout << ret << endl;
    
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}