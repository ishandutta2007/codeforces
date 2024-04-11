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

int N;
map<vector<int>, double> M[64];
int st[64],num[64];

double dodo(int top,vector<int> V) {
    int otop,i,x,y,z,ng=0;
    
    otop=top=st[top];
    sort(V.begin(),V.end());
    vector<int> VV=V;
    
    if(M[top].find(V)!=M[top].end()) return M[top][V];
    
    if(num[top]==3) V.push_back(top), top=0, ng=1;
    
    double ma[4]={0,1e15,1e15,1e15};
    int pre=-1;
    FOR(i,V.size()-ng) {
        if(pre==V[i]) continue;
        pre=V[i];
        x=V[i]%4;
        y=V[i]/4%4;
        z=V[i]/16;
        
        vector<int> V2=V;
        V2.erase(V2.begin()+i);
        if(x&&y&&z) {
            if(top%4==0)           ma[y]=min(ma[y], dodo(top+y*1,V2));
            if(top/4%4==0)         ma[y]=min(ma[y], dodo(top+y*4,V2));
            if(top/16==0 && top%4) ma[y]=min(ma[y], dodo(top+y*16,V2));
        }
        
        if(z&&y) {
            if(x) {
                V[i]=4+x;
                if(top%4==0)           ma[z]=min(ma[z], dodo(top+z*1,V));
                if(top/4%4==0)         ma[z]=min(ma[z], dodo(top+z*4,V));
                if(top/16==0 && top%4) ma[z]=min(ma[z], dodo(top+z*16,V));
            }
            else {
                if(top%4==0)           ma[z]=min(ma[z], dodo(top+z*1,V2));
                if(top/4%4==0)         ma[z]=min(ma[z], dodo(top+z*4,V2));
                if(top/16==0 && top%4) ma[z]=min(ma[z], dodo(top+z*16,V2));
            }
        }
        if(y&&x) {
            if(z) {
                V[i]=z+4;
                if(top%4==0)           ma[x]=min(ma[x], dodo(top+x*1,V));
                if(top/4%4==0)         ma[x]=min(ma[x], dodo(top+x*4,V));
                if(top/16==0 && top%4) ma[x]=min(ma[x], dodo(top+x*16,V));
            }
            else {
                if(top%4==0)           ma[x]=min(ma[x], dodo(top+x*1,V2));
                if(top/4%4==0)         ma[x]=min(ma[x], dodo(top+x*4,V2));
                if(top/16==0 && top%4) ma[x]=min(ma[x], dodo(top+x*16,V2));
            }
        }
        V[i]=pre;
    }
    
    int sum=1;
    if(ma[1]>=1e15) ma[1]=0, sum+=1;
    if(ma[2]>=1e15) ma[2]=0, sum+=2;
    if(ma[3]>=1e15) ma[3]=0, sum+=2;
    if(sum==6) return M[otop][VV]=0;
    M[otop][VV]=(1+ma[1]/6 + ma[2]/3 + ma[3]/3)/(1-sum/6.0);
    return M[otop][VV]=(1+ma[1]/6 + ma[2]/3 + ma[3]/3)/(1-sum/6.0);
    
}

void solve() {
    int f,i,j,k,l,x,y,x2,y2,z;
    
    cin>>N;
    string S;
    
    FOR(i,64) {
        x=i%4;
        y=i/4%4;
        z=i/16;
        st[i]=(z>x)?(x*16+y*4+z):i;
        num[i]=(x>0)+(y>0)+(z>0);
    }
    
    vector<int> V;
    FOR(i,N) {
        cin>>S;
        x=0;
        FOR(y,3) {
            if(S[y]=='R') x+=1<<(y*2);
            if(S[y]=='G') x+=2<<(y*2);
            if(S[y]=='B') x+=3<<(y*2);
        }
        if(i<N-1) V.push_back(st[x]);
    }
    _P("%.12lf\n",dodo(st[x],V));
    
}


int main(int argc,char** argv){
    string s;
    if(argc==1) ios::sync_with_stdio(false);
    for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
    for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
    solve();
    return 0;
}