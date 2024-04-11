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

int N;
int X[10001],Y[10001],RX,RY;

vector<pair<int,int> > OX,OY,XY;

void diag(int V[],int& r,vector<pair<int,int> >& VP) {
    int i,j,k;
    for(i=30;i>=0;i--) {
        for(j=r;j<N;j++) if(V[j]&(1<<i)) {
            if(j!=r) {
                VP.push_back(make_pair(j,r));
                VP.push_back(make_pair(r,j));
                VP.push_back(make_pair(j,r));
                swap(V[j],V[r]);
            }
            FOR(j,N) if(j!=r && (V[j]&(1<<i))) {
                VP.push_back(make_pair(j,r));
                V[j]^=V[r];
            }
            r++;
            break;
        }
    }
}

void solve() {
    int i,j,k,l,r,x,y; string s;
    
    cin>>N;
    FOR(i,N) cin>>X[i];
    FOR(i,N) cin>>Y[i];
    diag(X,RX,OX);
    diag(Y,RY,OY);
    reverse(OY.begin(),OY.end());
    if(RX<RY) return _P("-1\n");
    
    FOR(i,RX) if(X[i]) {
        int msb=1;
        while(msb*2<=X[i]) msb*=2;
        FOR(j,RX) if((Y[j]&msb) && i!=j) {
            XY.push_back(make_pair(j,i));
            X[j]^=X[i];
        }
        if(!(Y[i]&msb)) {
            XY.push_back(make_pair(i,i));
            X[i]=0;
        }
    }
    
    FOR(i,RX) if(X[i]!=Y[i]) return _P("-1\n");
    _P("%d\n",OX.size()+XY.size()+OY.size());
    ITR(it,OX) _P("%d %d\n",it->first+1,it->second+1);
    ITR(it,XY) _P("%d %d\n",it->first+1,it->second+1);
    ITR(it,OY) _P("%d %d\n",it->first+1,it->second+1);
}


int main(int argc,char** argv){
    string s;int i;
    if(argc==1) ios::sync_with_stdio(false);
    FOR(i,argc-1) s+=argv[i+1],s+='\n';
    FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
    solve(); return 0;
}