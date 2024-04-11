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

ll N,K;
int memo[10000001],memo2[10001];
map<int,vector<int> > M[2];

int wavy(ll v) {
    int num[15],d,i;
    
    while(v>=10000000) {
        if(memo[v%10000000]==0) return 0;
        v/=100000;
    }
    while(v>=10000) {
        if(memo2[v%10000]==0) return 0;
        v/=100;
    }
    
    if(v<10) return 1;
    if(v<100) return (v%10!=v/10);
    
    FOR(d,15) {
        if(v==0) break;
        num[d]=v%10;
        v/=10;
    }
    for(i=1;i<d-1;i++) {
        if(num[i-1]==num[i]||num[i+1]==num[i]) return 0;
        if(num[i-1]<num[i] != num[i+1]<num[i]) return 0;
    }
    return 1;
}

void dfs(int cur,int left) {
    int i;
    if(left==0) {
        memo[cur]=1+((cur%10)<(cur/10%10));
        if(N<10000000) M[memo[cur]-1][cur%N].push_back(cur);
        return;
    }
    if(cur/10%10 < cur%10) {
        FOR(i,cur%10) dfs(cur*10+i,left-1);
    }
    else {
        for(i=cur%10+1;i<10;i++) dfs(cur*10+i,left-1);
    }
}


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>K;
    
    FOR(i,100) if(i%10 != i/10) dfs(i,5);
    FOR(i,10000) memo2[i]|=i/100%10<i/10%10 && i%10<i/10%10 && i/1000>i/100%10;
    FOR(i,10000) memo2[i]|=i/100%10>i/10%10 && i%10>i/10%10 && i/1000<i/100%10;
    
    if(N>=10000000) {
        for(ll v=N;v<=10000000LL*10000000; v+=N) if(wavy(v) && --K==0) return _P("%lld\n",v);
        return _P("-1\n");
    }
    for(i=N;i<10000000;i+=N) if(wavy(i) && --K==0) return _P("%d\n",i);
    
    for(ll v=1;v<=9999999; v++) {
        int mo=(N-(v*10000000%N)) % N;
        if(wavy(v)==0) continue;
        
        if((v<10 || (v%10>v/10%10)) && M[1].count(mo)) {
            x = lower_bound(M[1][mo].begin(),M[1][mo].end(),(int)(v%10)*1000000)-M[1][mo].begin();
            if(K<=x) return _P("%lld\n",v*10000000+M[1][mo][K-1]);
            K-=x;
        }
        if((v<10 || (v%10<v/10%10)) && M[0].count(mo)) {
            x = lower_bound(M[0][mo].begin(),M[0][mo].end(),(int)(1+(v%10))*1000000)-M[0][mo].begin();
            K-=M[0][mo].size()-x;
            if(K<=0) return _P("%lld\n",v*10000000+M[0][mo][M[0][mo].size()-1+K]);
        }
    }
    return _P("-1\n");
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}