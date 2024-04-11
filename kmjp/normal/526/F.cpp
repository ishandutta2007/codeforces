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

int N;
int X[400000];
int MX[400000],MN[400000];
ll ret;
int cnt1[800000],cnt2[800000];

ll dp(int L,int R) {
    if(L>=R) return 0;
    if(L+1==R) return 1;
    if(L+2==R) return 2+(abs(X[L]-X[L+1])==1);
    int M=(L+R)/2,i,x1,x2,y1,y2;
    ll ret = dp(L,M) + dp(M,R);
    
    MX[M]=MN[M]=X[M];
    MX[M-1]=MN[M-1]=X[M-1];
    for(i=M-2;i>=L;i--) MX[i]=max(MX[i+1],X[i]),MN[i]=min(MN[i+1],X[i]);
    for(i=M+1;i<R;i++)  MX[i]=max(MX[i-1],X[i]),MN[i]=min(MN[i-1],X[i]);
    
    for(i=L;i<R;i++) {
        int num=MX[i]-MN[i];
        if(i<M && i+num>=M && i+num<R && MX[i+num]<MX[i] && MN[i+num]>MN[i]) ret++;
        if(i>=M && i-num<M && i-num>=L && MX[i-num]<MX[i] && MN[i-num]>MN[i]) ret++;
    }
    
    for(i=M-1, x1=x2=y1=y2=M;i>=L;i--) {
        while(x1<R && MN[x1]>MN[i])  cnt1[MX[x1]-x1+400000]++, x1++;
        while(x2<x1 && MX[x2]<MX[i]) cnt1[MX[x2]-x2+400000]--, x2++;
        while(y1<R && MX[y1]<MX[i])  cnt2[y1+MN[y1]]++, y1++;
        while(y2<y1 && MN[y2]>MN[i]) cnt2[y2+MN[y2]]--, y2++;
        ret += cnt1[MN[i]-i+400000] + cnt2[i+MX[i]];
    }
    while(x2<x1) cnt1[MX[x2]-x2+400000]--, x2++;
    while(y2<y1) cnt2[y2+MN[y2]]--, y2++;
    return ret;
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>x>>y, X[x]=y;
    cout<<dp(1,N+1)<<endl;
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}