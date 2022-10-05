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

int N,S;
int V[1003];
int in[1003],out[1003],w[1003],s[1003],v[1003];
int dp[1003][1003];

int cmp(int a,int b) {
    if(out[a]<out[b]) return 1;
    if(out[a]>out[b]) return 0;
    return in[a]>in[b];
}

void solve() {
    int i,j,k,l,r,x,y;
    
    cin>>N>>S;
    FOR(i,N) cin>>in[i]>>out[i]>>w[i]>>s[i]>>v[i];
    in[N]=0,out[N]=1000,s[N]=S;
    N++;
    FOR(i,N) V[i]=i;
    sort(V,V+N,cmp);
    FOR(i,N) {
        for(x=w[V[i]];x<=S;x++) {
            int dp2[1002];
            ZERO(dp2);
            int mw=min(x-w[V[i]],s[V[i]]);
            y=in[V[i]];
            FOR(j,i) if(in[V[j]]>=in[V[i]]) {
                for(;y<=in[V[j]];y++) dp2[y]=max(dp2[y],(y-1>=0)?dp2[y-1]:0);
                dp2[out[V[j]]]=max(dp2[out[V[j]]], dp[j][mw]+dp2[in[V[j]]]);
            }
            dp[i][x]=*max_element(dp2,dp2+out[V[i]]+1)+v[V[i]];
        }
    }
    cout << dp[N-1][S] << endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}