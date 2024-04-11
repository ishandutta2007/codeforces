#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N,M;
int U[300055],V[300055],W[300055];
vector<pair<int,int> > E[100005];
int ma[300005][2];

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M;
    FOR(i,M) {
        cin>>U[i]>>V[i]>>W[i];
        E[W[i]].push_back(make_pair(U[i]-1,V[i]-1));
    }
    FOR(i,100001) {
        FOR(j,E[i].size()) {
            int cur=E[i][j].first,tar=E[i][j].second;
            ma[cur][1]=ma[cur][0];
        }
        FOR(j,E[i].size()) {
            int cur=E[i][j].first,tar=E[i][j].second;
            if(ma[cur][1]+1>ma[tar][0]) ma[tar][0]=ma[cur][1]+1;
        }
    }
    int ret=0;
    FOR(i,N) ret=max(ret,max(ma[i][0],ma[i][1]));
    cout << ret << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}