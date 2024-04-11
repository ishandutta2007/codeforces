#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int step[500000];
void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>M;
    FOR(i,400000) step[i]=1000000;
    step[N]=0;
    queue<int> q;
    q.push(N);
    while(q.size()) {
        x=q.front();
        q.pop();
        if(x-1>0 && step[x-1]>step[x]+1) step[x-1]=step[x]+1, q.push(x-1);
        if(x*2<400000 && step[x*2]>step[x]+1) step[x*2]=step[x]+1, q.push(x*2);
    }
    
    cout<<step[M]<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}