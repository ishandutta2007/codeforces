#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,X[100006],Y[100006];
vector< vector<pair<int,int> > > H;

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    H.resize(2000005);
    cin>>N;
    FOR(i,N) cin>>X[i]>>Y[i], X[i]+=1000000, Y[i]+=1000000;
    
    
    double ret=0;
    double T;
    FOR(k,2) {
        T=0;
        FOR(x,2000001) H[x].clear();
        FOR(i,N) {
            H[X[i]].push_back(make_pair(Y[i],Y[i]));
            if(X[i]!=X[(i+1)%N]) {
                int dx=(X[i]<X[(i+1)%N])?1:-1;
                for(x=X[i]+dx;x!=X[(i+1)%N];x+=dx) {
                    ll dy=1LL*(x-X[i])*(Y[(i+1)%N]-Y[i]);
                    ll y2=Y[i]+dy/(X[(i+1)%N]-X[i]);
                    if((dy>=0) ^ (X[(i+1)%N]<X[i]))
                        H[x].push_back(make_pair(y2,y2+((dy%(X[(i+1)%N]-X[i])!=0))));
                    else
                        H[x].push_back(make_pair(y2-(dy%(X[(i+1)%N]-X[i])!=0),y2));
                }
            }
        }
        
        double S1=0,S2=0;
        FOR(x,2000001) if(H[x].size()) {
            int mf=H[x][0].first,ms=H[x][0].second;
            FOR(i,H[x].size()) mf=max(mf,H[x][i].first),ms=min(ms,H[x][i].second);
            int h=mf-ms+1;
            if(h<=0) continue;
            ret += h*(T*x*x-2LL*x*S1+S2);
            T+=h;
            S1+=1LL*h*x;
            S2+=1LL*h*x*x;
        }
        FOR(i,N) swap(X[i],Y[i]);
    }
    _P("%.12lf\n",ret/(T-1.0)/T);
    
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}