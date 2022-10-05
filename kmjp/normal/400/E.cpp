#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
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
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N,M;
int A[100002];
map<int,int> L[20];
ll tot[20];

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N>>M;
    FOR(i,N) {
        cin>>A[i];
        FOR(j,20) if(A[i]&(1<<j)) {
            if(L[j].empty()) L[j][i]=1;
            else {
                map<int,int>::iterator it=L[j].end();
                it--;
                if(it->first+it->second==i) it->second++;
                else L[j][i]=1;
            }
        }
    }
    FOR(j,20) ITR(it,L[j]) tot[j]+=it->second*(ll)(it->second+1)/2;
    
    
    FOR(i,M) {
        cin>>x>>y;
        x--;
        ll t=0;
        FOR(j,20) {
            map<int,int>::iterator it=L[j].upper_bound(x);
            if((A[x]&(1<<j))>0 && (y&(1<<j))==0) {
                it--;
                tot[j]-=it->second*(ll)(it->second+1)/2;
                if(it->first+it->second-1!=x) {
                    L[j][x+1]=it->first+it->second-1-x;
                    tot[j]+=L[j][x+1]*(ll)(L[j][x+1]+1)/2;
                }
                if(it->first==x) {
                    L[j].erase(it);
                }
                else {
                    it->second=x-it->first;
                    tot[j]+=it->second*(ll)(it->second+1)/2;
                }
            }
            if((A[x]&(1<<j))==0 && (y&(1<<j))>0) {
                if(it==L[j].begin()) {
                    if(it!=L[j].end() && it->first==x+1) {
                            tot[j]-=it->second*(ll)(it->second+1)/2;
                            tot[j]+=(it->second+1)*(ll)(it->second+2)/2;
                            L[j][x]=1+it->second;
                            L[j].erase(it);
                    }
                    else {
                        tot[j]++;
                        L[j][x]=1;
                    }
                }
                else {
                    map<int,int>::iterator bit=it;
                    bit--;
                    
                    if(bit->first+bit->second==x) {
                        tot[j]-=bit->second*(ll)(bit->second+1)/2;
                        if(it!=L[j].end() && it->first==x+1) {
                            tot[j]-=it->second*(ll)(it->second+1)/2;
                            bit->second+=1+it->second;
                            L[j].erase(it);
                            
                        }
                        else {
                            bit->second++;
                        }
                        tot[j]+=bit->second*(ll)(bit->second+1)/2;
                    }
                    else {
                        if(it!=L[j].end() && it->first==x+1) {
                                tot[j]-=it->second*(ll)(it->second+1)/2;
                                tot[j]+=(it->second+1)*(ll)(it->second+2)/2;
                                L[j][x]=1+it->second;
                                L[j].erase(it);
                        }
                        else {
                            tot[j]++;
                            L[j][x]=1;
                        }
                    }
                    
                }
                
            }
            //if(tot[j]>0) _P("%d %d %lld %d\n",i,j,tot[j],tot[j]<<j);
            t += tot[j]<<j;
        }
        cout << t << endl;
        A[x]=y;
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