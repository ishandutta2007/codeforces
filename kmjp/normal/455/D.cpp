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

const int SP=300;
int N,Q;
deque<int> D[500];
int sum[501][100002];
int lastans;

void solve() {
    int f,i,j,k,l,x,y,r;
    
    cin>>N;
    FOR(i,N) {
        cin>>x;
        D[i/SP].push_back(x-1);
        sum[i/SP][x-1]++;
    }
    cin>>Q;
    while(Q--) {
        cin>>i>>l>>r;
        l=(l+lastans-1)%N;
        r=(r+lastans-1)%N;
        if(l>r) swap(l,r);
        
        if(i==1) {
            j=D[r/SP][r%SP];
            sum[r/SP][j]--;
            D[r/SP].erase(D[r/SP].begin()+r%SP);
            sum[l/SP][j]++;
            D[l/SP].insert(D[l/SP].begin()+l%SP,j);
            
            FOR(i,500) while(D[i].size()>SP) {
                j=D[i].back();
                D[i].pop_back();
                sum[i][j]--;
                D[i+1].push_front(j);
                sum[i+1][j]++;
            }
        }
        else {
            cin>>k;
            k=(k+lastans-1)%N;
            r++;
            lastans=0;
            FOR(i,500) {
                if(i<r/SP) lastans+=sum[i][k];
                if(i<l/SP) lastans-=sum[i][k];
                if(i==r/SP) {
                    FOR(j,r%SP) lastans+=D[i][j]==k;
                }
                if(i==l/SP) {
                    FOR(j,l%SP) lastans-=D[i][j]==k;
                }
            }
            cout<<lastans<<endl;
        }
        
    }
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}