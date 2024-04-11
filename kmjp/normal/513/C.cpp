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
int L[6],R[6];
int p3[7];
double ret=0;
void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>L[i]>>R[i];
    p3[0]=1;
    FOR(i,6) p3[i+1]=p3[i]*3;
    
    for(i=1;i<=10000;i++) {
        for(int mask=0;mask<p3[N];mask++) {
            int hoge[3]={};
            FOR(x,N) hoge[mask/p3[x]%3]++;
            if(hoge[2]>1) continue;
            if(hoge[1]==0) continue;
            if(hoge[1]==1 && hoge[2]==0) continue;
            double tmp=1;
            
            FOR(x,N) {
                int rr=R[x],ll=L[x];
                if(mask/p3[x]%3==0) rr=min(rr,i-1);
                if(mask/p3[x]%3==1) ll=max(ll,i),rr=min(rr,i);
                if(mask/p3[x]%3==2) ll=max(ll,i+1);
                if(rr-ll+1<=0) tmp=0;
                else tmp *= (rr-ll+1.0)/(R[x]-L[x]+1);
            }
            ret += tmp*i;
        }
    }
    _P("%.12lf\n",ret);
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}