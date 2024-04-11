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

int M;
int B[100001];
int pre[100001], pre2[100001];
int post[100001], post2[100001];
int la[2][100001];

int Q;
int L[100001],R[100001];
pair<pair<int,int>,pair<int,int> > P[100001];

int tnum,ok;
int num[100001],res[100001];


void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>M;
    FOR(i,100001) la[0][i]=0, la[1][i]=M+1;
    for(i=1;i<=M;i++) {
        cin>>B[i];
        pre[i]=x=la[0][B[i]];
        la[0][B[i]]=i;
        if(i-x==x-pre[x]) pre2[i]=pre2[x];
        else pre2[i]=pre[x]+1;
    }
    post[M+1]=post2[M+1]=M+1;
    for(i=M;i>=1;i--) {
        post[i]=x=la[1][B[i]];
        la[1][B[i]]=i;
        if(i-x==x-post[x]) post2[i]=post2[x];
        else post2[i]=post[x]-1;
    }
    
    cin>>Q;
    FOR(i,Q) {
        cin>>L[i]>>R[i];
        P[i]=make_pair(make_pair(L[i]/300,R[i]),make_pair(L[i],i));
    }
    sort(P,P+Q);
    
    l=1,r=1;
    tnum=ok=1;
    num[B[1]]=1;
    FOR(i,Q) {
        j=P[i].second.second;
        while(L[j]<l) {
            l--;
            if(num[B[l]]++==0) tnum++, ok++;
            else if(post2[post[l]]>=r && post2[l]<r) ok--;
        }
        while(r<R[j]) {
            r++;
            if(num[B[r]]++==0) tnum++, ok++;
            else if(pre2[pre[r]]<=l && pre2[r]>l) ok--;
        }
        while(l<L[j]) {
            if(--num[B[l]]==0) tnum--, ok--;
            else if(post2[l]<r && post2[post[l]]>=r) ok++;
            l++;
        }
        while(R[j]<r) {
            if(--num[B[r]]==0) tnum--, ok--;
            else if(pre2[r]>l && pre2[pre[r]]<=l) ok++;
            r--;
        }
        res[j]=tnum+(ok==0);
    }
    
    FOR(i,Q) cout<<res[i]<<endl;
    
    
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}