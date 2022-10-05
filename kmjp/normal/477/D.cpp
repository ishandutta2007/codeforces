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

string S;
int L;
ll mo=1000000007;
int pat[5005][5005],pats[5005][5005];
int mi[5005][5005],mis[5005][5005];
int mat[5005][5005];
char C[5005];


void lcs(string& AA,string& BB) {
    int x,y,ma=0;
    for(x=AA.size()-1;x>=0;x--) for(y=BB.size()-1;y>=0;y--)
        mat[x][y]=(AA[x]==BB[y])?(mat[x+1][y+1]+1):0;
}
bool lessthan(int pre,int cur) {
    int l=cur-pre;
    if(mat[pre][cur]>=l) return true;
    return C[pre+mat[pre][cur]]<C[cur+mat[pre][cur]];
    
}

ll val(int cur) {
    ll v=0;
    while(cur<L) v=(2*v+(S[cur++]=='1'))%mo;
    return v;
}

ll dpdp(int pre,int cur);
ll dpdp2(int cur,int tar) {
    if(pats[cur][tar]>=0) return pats[cur][tar];
    if(tar>L) return pats[cur][tar]=0;
    pats[cur][tar]=dpdp2(cur,tar+1)+dpdp(cur,tar);
    if(pats[cur][tar]>=mo) pats[cur][tar]-=mo;
    return pats[cur][tar];
}

ll dpdp(int pre,int cur) {
    if(pat[pre][cur]!=-1) return pat[pre][cur];
    if(cur==L) return pat[pre][cur]=1;
    if(S[cur]=='0') return pat[pre][cur]=0;
    
    ll ret=0;
    int tar=cur+(cur-pre);
    if(tar<=L && pre!=cur && lessthan(pre,cur)) ret+=dpdp(cur,tar);
    ret+=dpdp2(cur,tar+1);
    return pat[pre][cur]=ret%mo;
}

int mimi(int pre,int cur);
int mimi2(int cur,int tar) {
    if(mis[cur][tar]>=0) return mis[cur][tar];
    if(cur>=tar) return mis[cur][tar]=6000;
    mis[cur][tar]=min(mimi2(cur+1,tar),mimi(cur,tar));
    return mis[cur][tar]=min(mimi2(cur+1,tar),mimi(cur,tar));
}

int mimi(int pre,int cur) {
    if(mi[pre][cur]!=-1) return mi[pre][cur];
    if(S[pre]=='0') return 6000;
    if(pre==0) return mi[pre][cur]=1;
    int& ret=mi[pre][cur]=6000;
    
    int i=cur-pre;
    if(pre-i>=0 && lessthan(pre-i,pre)) ret=min(ret,mimi(pre-i,pre)+1);
    ret=min(ret,mimi2(max(0,pre-i+1),pre)+1);
    return ret;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>S;
    L=S.size();
    strncpy(C,S.c_str(),L);
    C[L]=0;
    MINUS(pat);
    MINUS(pats);
    MINUS(mi);
    MINUS(mis);
    
    lcs(S,S);
    dpdp(0,0);
    
    ll ret=1LL<<50;
    for(i=1;i<=L;i++) if(S[L-i]=='1' && mimi(L-i,L)<6000 && i<=20) ret=min(ret,mimi(L-i,L)+val(L-i));
    for(i=21;i<=L;i++) if(S[L-i]=='1' && mimi(L-i,L)<6000 && ret==1LL<<50) ret=mimi(L-i,L)+val(L-i);
    
    _P("%d\n%lld\n",pat[0][0],ret);
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}