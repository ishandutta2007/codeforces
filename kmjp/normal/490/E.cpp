#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int V[100005];
int p10[10];

int more(string s,int v) {
    int q[10];
    int L=s.size();
    int i,j;
    while(1) {
        
        int val=0, tq=-1;
        FOR(i,L) if(s[i]=='?' && tq<0) tq=i;
        FOR(i,L) if(s[i]!='?') val += p10[L-1-i]*(s[i]-'0');
        
        if(tq==-1) {
            if(val>v) return val;
            else return -1;
        }
        
        FOR(i,L) if(s[i]=='?' && i>tq) val += p10[L-1-i]*9;
        FOR(j,10) {
            s[tq]='0'+j;
            if(tq==0 && j==0) continue;
            if(val + j*p10[L-1-tq] > v) break;
        }
        if(j==-1) return -1;
    }
    return -1;
    
    
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    p10[0]=1;
    FOR(i,8) p10[i+1]=p10[i]*10;
    
    cin>>N;
    FOR(i,N) {
        cin>>s;
        V[i+1]=more(s,V[i]);
        if(V[i+1]<0) return _P("NO\n");
    }
    
    
    
    _P("YES\n");
    FOR(i,N) _P("%d\n",V[i+1]);
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}