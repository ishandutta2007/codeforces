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

int N,Q;
ll H[100001];
ll tot,ma;
vector<int> VV[1001];
ll bucket[1001];

const int SP=300;
void solve() {
    int f,i,j,k,l,x,y;
    
    vector<pair<int,int> > VP;
    cin>>N>>Q;
    FOR(i,N) {
        cin>>H[i];
        VP.push_back(make_pair(H[i],i));
    }
    sort(VP.begin(),VP.end());
    FOR(i,N) {
        VV[i/SP].push_back(VP[i].first);
        bucket[i/SP]+=VP[i].first;
    }
    
    FOR(i,Q) {
        cin>>j;
        if(j==1) {
            cin>>x>>y;
            x--;
            FOR(k,1000) {
                if(H[x]<=VV[k].back()) break;
            }
            bucket[k]-=H[x];
            FOR(j,VV[k].size()) {
                if(VV[k][j]==H[x]) {
                    VV[k].erase(VV[k].begin()+j);
                    break;
                }
            }
            
            if(VV[k].empty() || VV[k].size()+VV[k+1].size()<=SP) {
                ITR(it,VV[k+1]) VV[k].push_back(*it);
                bucket[k]+=bucket[k+1];
                VV[k+1].clear();
                bucket[k+1]=0;
                for(j=k+1;j<999;j++) {
                    swap(VV[j],VV[j+1]);
                    swap(bucket[j],bucket[j+1]);
                }
            }
            
            
            H[x]=y;
            FOR(j,999) {
                if(VV[j+1].empty() || y<VV[j+1].front()) break;
            }
            VV[j].push_back(y);
            sort(VV[j].begin(),VV[j].end());
            bucket[j]+=y;
            if(VV[j].size()>=2*SP) {
                for(k=999;k>j;k--) {
                    swap(bucket[k],bucket[k+1]);
                    swap(VV[k],VV[k+1]);
                }
                VV[j+1].clear();
                bucket[j+1]=0;
                for(k=SP;k<VV[j].size();k++) {
                    VV[j+1].push_back(VV[j][k]);
                    bucket[j+1]+=VV[j][k];
                    bucket[j]-=VV[j][k];
                }
                VV[j].resize(SP);
            }
        }
        else {
            ll v,nc=0,tot=0;
            cin>>v;
            
            FOR(j,1000) {
                if(VV[j].empty()) {
                    _P("%.12lf\n",(v+tot)/(double)N);
                    break;
                }
                ll nc2=nc+VV[j].size(),tot2=tot+bucket[j];
                if(!VV[j+1].empty() && (v+tot2)> VV[j+1][0]*nc2) {
                    tot=tot2;
                    nc=nc2;
                    continue;
                }
                
                FOR(x,VV[j].size()) {
                    if(nc && (v+tot)<=VV[j][x]*nc) break;
                    tot+=VV[j][x];
                    nc++;
                }
                _P("%.12lf\n",(v+tot)/(double)nc);
                break;
            }
            out:
            ;
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