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

int N,T;
double P;
int TT;
double P2[2][6001];
double ret;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N>>T;
    
    P2[0][0]=1;
    double ret=0;
    FOR(i,N) {
        int cur=i%2,tar=cur^1;
        
        cin>>P>>TT;
        if(P==100) TT=1;
        if(TT==1) P=100;
        P/=100;
        
        double pt1=pow(1-P,TT-2)*P;
        double pt0=pow(1-P,TT-1);
        if(pt1<1e-13) pt1=0;
        if(pt0<1e-13) pt0=0;
        
        ZERO(P2[tar]);
        
        double tt=0,left=1;
        for(j=i+1;j<=T;j++) {
            if(TT==1) {
                tt=P2[cur][j-1];
            }
            else {
                if(j>=(TT+1) && pt0) tt-=P2[cur][j-(TT+1)]*pt0;
                if(j>=(TT) && pt1) tt-=P2[cur][j-TT]*pt1;
                tt*=1-P;
                if(j>=(TT) && pt0) tt+=P2[cur][j-TT]*pt0;
                tt+=P2[cur][j-1]*P;
            }
            ret += tt;
            left-=tt;
            if(tt>1e-15)  P2[tar][j]=tt;
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