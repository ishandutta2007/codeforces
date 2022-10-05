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
int S[201000];
const char* ss="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";


int in[64*64],out[64*64];
int num[64*64*64];
string R;

void dfs(int cur) {
    int i;
    FOR(i,64) {
        while(num[cur*64+i]) {
            num[cur*64+i]--;
            dfs(cur%64*64+i);
        }
    }
    R+=ss[cur%64];
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) {
        cin>>s;
        S[i]=(lower_bound(ss,ss+62,s[0])-ss)*64*64;
        S[i]+=(lower_bound(ss,ss+62,s[1])-ss)*64;
        S[i]+=(lower_bound(ss,ss+62,s[2])-ss);
        num[S[i]]++;
        in[S[i]/64]++;
        out[S[i]%(64*64)]++;
    }
    
    int st=-1;
    FOR(i,64*64) {
        if(in[i]==out[i]) continue;
        else if(in[i]==out[i]+1) {
            if(st!=-1) return _P("NO\n");
            st=i;
        }
        else if(in[i]+1==out[i]) continue;
        else return _P("NO\n");
    }
    
    if(st==-1) FOR(i,64*64) if(in[i]) st=i;
    
    dfs(st);
    R+=ss[st/64];
    reverse(R.begin(),R.end());
    if(R.size()!=N+2) return _P("NO\n");
    
    cout<<"YES"<<endl;
    cout<<R<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}