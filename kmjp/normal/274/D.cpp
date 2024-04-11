#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,T;
set<int> E[200010];
vector<int> R;
int in[200010];

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    T=M;
    FOR(i,N) {
        map<int,vector<int> > MM;
        FOR(x,M) {
            cin>>y;
            if(y!=-1) MM[y].push_back(x);
        }
        if(MM.size()<2) continue;
        map<int,vector<int> >::iterator it1,it2;
        for(it2=MM.begin(),it1=it2++;it1!=MM.end()&&it2!=MM.end();it1++,it2++) {
            vector<int> &v1=it1->second,&v2=it2->second;
            if(v1.size()<=2 || v2.size()<=2) {
                FOR(x,v1.size()) FOR(y,v2.size()) E[v1[x]].insert(v2[y]);
            }
            else {
                FOR(x,v1.size()) E[v1[x]].insert(T);
                FOR(y,v2.size()) E[T].insert(v2[y]);
                T++;
            }
        }
    }
    
    queue<int> Q;
    FOR(i,T) ITR(it,E[i]) in[*it]++;
    FOR(i,T) if(in[i]==0) Q.push(i);
    while(!Q.empty()) {
        int cur=Q.front();
        Q.pop();
        if(cur<M) R.push_back(cur);
        ITR(it,E[cur]) if(--in[*it]==0) Q.push(*it);
    }
    
    if(R.size()<M) return _P("-1\n");
    FOR(i,M) _P("%d ",R[i]+1);
    _P("\n");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}