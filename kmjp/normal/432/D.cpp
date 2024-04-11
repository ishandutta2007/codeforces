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

vector<int> Zalgo(string s) {
    int l=-1,r=-1,i;
    vector<int> v;
    v.push_back(s.size());
    for(i=1;i<s.size();i++) {
        if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
        else {
            l=i; r=(i>r)?i:(r+1);
            while(r<s.size() && s[r-i]==s[r]) r++;
            v.push_back((r--)-l);
        }
    }
    return v;
}

string S;
int num[100001],sum[100001];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>S;
    
    int N=S.size();
    vector<int> V = Zalgo(S);
    vector<pair<int,int> > R;
    FOR(i,N) num[V[i]]++;
    for(i=N;i>=0;i--) sum[i]=sum[i+1]+num[i];
    for(i=1;i<=N;i++) if(V[N-i]==i) R.push_back(make_pair(i,sum[i]));
    _P("%d\n",R.size());
    FOR(i,R.size()) _P("%d %d\n",R[i].first,R[i].second);
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}