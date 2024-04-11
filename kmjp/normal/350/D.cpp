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
void _fill_ll(ll* p,ll val,int rep) {int i; FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define MINUSL(a) _fill_ll((ll*)a,-1LL,sizeof(a)/8)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N,M;
int X1[400000],X2[400000],Y1[400000],Y2[400000];
int X3[10000],Y3[10000],R[10000];
map<pair<ll,ll>,vector<int> > S1,S2;

void solve() {
    int f,i,j,k,l, x,y;
    int sx,sy;
    
    cin>>N>>M;
    FOR(i,N) {
        cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i];
        X1[i]*=2;
        Y1[i]*=2;
        X2[i]*=2;
        Y2[i]*=2;
        if(X1[i]==X2[i]) {
            S1[make_pair(X1[i],1LL<<40)].push_back(min(Y1[i],Y2[i]));
            S2[make_pair(X1[i],1LL<<40)].push_back(max(Y1[i],Y2[i]));
        }
        else if(Y1[i]==Y2[i]) {
            S1[make_pair(1LL<<40,Y1[i])].push_back(min(X1[i],X2[i]));
            S2[make_pair(1LL<<40,Y1[i])].push_back(max(X1[i],X2[i]));
        }
        else {
            ll den=(Y2[i]-Y1[i])*(-X1[i])+Y1[i]*(X2[i]-X1[i]);
            ll num=X2[i]-X1[i];
            ll g=__gcd(den,num);
            den/=g; num/=g;
            if(num<0) den=-den,num=-num;
            ll YY = den*1000000000 + num;
            //_P("%lld/%lld:%lld : ",den,num,YY);
            den=(X2[i]-X1[i])*(-Y1[i])+X1[i]*(Y2[i]-Y1[i]);
            num=Y2[i]-Y1[i];
            g=__gcd(den,num);
            den/=g; num/=g;
            if(num<0) den=-den,num=-num;
            ll XX = den*1000000000 + num;
            //_P("%lld/%lld:%lld\n",den,num,XX);
            S1[make_pair(XX,YY)].push_back(min(X1[i],X2[i]));
            S2[make_pair(XX,YY)].push_back(max(X1[i],X2[i]));
        }
    }
    ITR(it,S1) sort(it->second.begin(),it->second.end());
    ITR(it,S2) sort(it->second.begin(),it->second.end());
    
    FOR(i,M) {
        cin>>X3[i]>>Y3[i]>>R[i];
        X3[i]*=2;
        Y3[i]*=2;
        R[i]*=2;
    }
    
    int ret=0;
    FOR(x,M) for(y=x+1;y<M;y++) {
        if(R[x]!=R[y]) continue;
        if((Y3[y]-Y3[x])*(ll)(Y3[y]-Y3[x])+(X3[y]-X3[x])*(ll)(X3[y]-X3[x]) <= 4*(ll)R[x]*R[x]) continue;
        
        int CX=(X3[x]+X3[y])/2,CY=(Y3[x]+Y3[y])/2;
        
        __typeof(S1.begin()) its1,its2;
        pair<ll,ll> k;
        if(X3[x]==X3[y]) k=make_pair(1LL<<40,CY);
        else if(Y3[x]==Y3[y]) k=make_pair(CX,1LL<<40);
        else {
            ll num=Y3[y]-Y3[x];
            ll den=CX*(X3[y]-X3[x])+CY*num;
            ll g=__gcd(den,num);
            den/=g; num/=g;
            if(num<0) den=-den,num=-num;
            k.second = den*1000000000 + num;
            //_P("++ %lld/%lld:%lld : ",den,num,YY);
            num=X3[y]-X3[x];
            den=(Y3[y]-Y3[x])*CY+CX*num;
            g=__gcd(den,num);
            den/=g; num/=g;
            if(num<0) den=-den,num=-num;
            k.first = den*1000000000 + num;
            //_P("%lld/%lld:%lld\n",den,num,XX);
        }
        its1=S1.find(k);
        its2=S2.find(k);
        if(its1 == S1.end()) continue;
        
        __typeof(its1->second.begin()) it1,it2;
        if(Y3[x]==Y3[y]) {
            it1=upper_bound(its1->second.begin(),its1->second.end(),CY);
            it2=lower_bound(its2->second.begin(),its2->second.end(),CY);
        }
        else {
            it1=upper_bound(its1->second.begin(),its1->second.end(),CX);
            it2=lower_bound(its2->second.begin(),its2->second.end(),CX);
        }
        
        ret += (it1-its1->second.begin())-(it2-its2->second.begin());
    }
    
    _P("%d\n",ret);
    
}


int main(int argc,char** argv){
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}