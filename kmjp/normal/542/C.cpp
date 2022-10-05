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
int F[300];
ll fir[300],per[300];
ll ret=1;
ll maf;
void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    for(i=1;i<=N;i++) cin>>F[i];
    for(i=1;i<=N;i++) {
        int ind[300]={};
        MINUS(ind);
        x=0;
        y=i;
        ind[i]=0;
        while(1) {
            x++;
            y=F[y];
            if(ind[y]>=0) {
                fir[i]=ind[y];
                per[i]=x-ind[y];
                break;
            }
            ind[y]=x;
        }
        fir[i]=(fir[i]+per[i]-1)/per[i]*per[i];
        maf = max(maf,fir[i]);
        ret = per[i]*(ret/__gcd(ret,per[i]));
    }
    
    ll tmp=ret;
    while(ret<maf) ret+=tmp;
    cout<<ret<<endl;
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}