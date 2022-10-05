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

int N,K;
double Y[301][301];
double S[301];

void solve() {
    int f,i,j,k,l,x,y;
    cin>>N>>K;
    FOR(i,N) FOR(x,K+1) cin>>Y[i][x];
    
    FOR(x,K) {
        map<double,double> M;
        M[0]=0;
        M[1]=0;
        FOR(i,N) {
            map<double,double> M2;
            M2[0]=M[0];
            double prex=0,prey=M[0];
            ITR(it,M) {
                if(it->first==0) continue;
                double cx = it->first;
                double cy = it->second;
                double y1= Y[i][x]+(Y[i][x+1]-Y[i][x])*prex;
                double y2= Y[i][x]+(Y[i][x+1]-Y[i][x])*cx;
                
                
                if(y1>=prey && y2>=cy) {
                    S[i] += ((y1+y2)-(cy+prey))*(cx-prex)/2.0;
                    M2[cx]=y2;
                }
                else if(y1<=prey && y2<=cy) {
                    M2[cx]=cy;
                }
                else if(y1>=prey && y2<=cy) {
                    double nx = prex + (cx-prex)*(abs(y1-prey)/(abs(y1-prey)+abs(y2-cy)));
                    double ny = prey + (cy-prey)*(abs(y1-prey)/(abs(y1-prey)+abs(y2-cy)));
                    
                    S[i] += ((y1-prey))*(nx-prex)/2.0;
                    M2[nx]=ny;
                    M2[cx]=cy;
                }
                else if(y1<=prey && y2>=cy) {
                    double nx = prex + (cx-prex)*(abs(y1-prey)/(abs(y1-prey)+abs(y2-cy)));
                    double ny = prey + (cy-prey)*(abs(y1-prey)/(abs(y1-prey)+abs(y2-cy)));
                    
                    S[i] += ((y2-cy))*(cx-nx)/2.0;
                    M2[nx]=ny;
                }
                prex = cx; prey= cy;
            }
            M2[0]=max(M2[0],Y[i][x]);
            M2[1]=max(M2[1],Y[i][x+1]);
            swap(M,M2);
            
        }
    }
    
    FOR(i,N) _P("%.12lf\n",S[i]);
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}