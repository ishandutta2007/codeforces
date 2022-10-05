#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int N,M,K;
ll mo=1000000007;
int L,R;
string LL,RR;
vector<string> S;
int V[201];

vector<vector<int> > TR;
vector<int> AC;

ll dpdp[2][201][501][2][2];

int find(string s) {
    int cur=0;
    ITR(it,s) if((cur=TR[cur][*it])==0) return -1;
    return cur;
}
void create(vector<string> S) {
    int i;
    TR.push_back(vector<int>(256));
    // trie
    ITR(it,S) {
        int cur=0;
        ITR(c,(*it)) {
            if(TR[cur][*c]==0) TR.push_back(vector<int>(256)),TR[cur][*c]=TR.size()-1;
            cur=TR[cur][*c];
        }
        AC.resize(TR.size());
        AC[cur]+=V[it-S.begin()];
    }
    // failure
    queue<int> Q;
    FOR(i,255) if(TR[0][i]) TR[TR[0][i]][255]=0, Q.push(TR[0][i]);
    
    while(!Q.empty()) {
        int k=Q.front(); Q.pop();
        //_P("++%d\n",k);
        FOR(i,255) if(TR[k][i]) {
            Q.push(TR[k][i]);
            int pre=TR[k][255];
            while(pre!=0 && TR[pre][i]==0) pre=TR[pre][255];
            TR[TR[k][i]][255]=TR[pre][i];
            AC[TR[k][i]] += AC[TR[pre][i]];
        }
    }
}

ll dodo(string SS) {
    ll ret=0,rr;
    int i,j,k,x,y,pos,val,b1,b2;
    
    ZERO(dpdp);
    dpdp[0][0][0][1][1]=1;
    //_P("+-%d\n",SS.size());
    FOR(i,SS.size()) {
        int cur=i%2,tar=cur^1;
        ZERO(dpdp[tar]);
        FOR(b1,2) FOR(b2,2) FOR(val,K+1) FOR(pos,TR.size()) if((rr = dpdp[cur][pos][val][b1][b2])) {
            //_P("%d %d %d %d %d : %lld\n",i,pos,val,b1,b2,rr);
            FOR(j,M) {
                if(b1 && j>SS[i]) break;
                y=(b1 && j==SS[i]);
                if(b2&&(j==0)) {
                    //_P("%d--%d\n",j,pos);
                    dpdp[tar][pos][val][y][1] += rr;
                    dpdp[tar][pos][val][y][1] %= mo;
                    continue;
                }
                x=pos;
                while(x && TR[x][j]==0) x=TR[x][255];
                x=TR[x][j];
                //_P("%d--%d->%d\n",j,pos,x);
                if(val+AC[x]<=K) {
                    dpdp[tar][x][val+AC[x]][y][0] += rr;
                    dpdp[tar][x][val+AC[x]][y][0] %= mo;
                }
            }
        }
    }
    x=SS.size()%2;
    FOR(i,201) FOR(j,K+1) ret+=dpdp[x][i][j][0][0]+dpdp[x][i][j][0][1]+dpdp[x][i][j][1][0]+dpdp[x][i][j][1][1];
    //cout << ret%mo << endl;
    return ret%mo;
}

void solve() {
    int f,i,j,k,l,x,y;
    
    cin>>N>>M>>K;
    cin>>L;
    FOR(i,L) cin>>x, LL+=x;
    cin>>R;
    FOR(i,R) cin>>x, RR+=x;
    
    FOR(i,N) {
        cin>>j;
        string s;
        while(j--) cin>>x, s+=x;
        S.push_back(s);
        cin>>V[i];
    }
    
    create(S);
    
    i=LL.size()-1;
    LL[i]-=1;
    while(LL[i]<0) LL[i]+=M, LL[--i]-=1;
    while(LL.size()>0 && LL[0]==0) LL.erase(LL.begin());
    //FOR(i,TR.size()) FOR(j,256) if(TR[i][j]) _P("%d %d %d\n",i,j,TR[i][j]);
    //FOR(i,AC.size()) _P("+%d %d\n",i,AC[i]);
    
    
    cout << (dodo(RR)-dodo(LL)+mo)%mo << endl;
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}