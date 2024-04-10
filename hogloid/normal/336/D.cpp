#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;

int n,m,g;
const lint mod=1000000007;

lint mpow(lint a,lint k){
    lint res=1;
    while(k>0){
        if(k&1) res=res*a%mod;
        a=a*a%mod;
        k>>=1;
    }
    return res;
}

lint invmod(lint a){
    return mpow(a,mod-2);
}
int main(){
    cin>>n>>m>>g;

    if(g==1){
        if(n==0){
            if(m==1) puts("1");
            else puts("0");
            return 0;
        }
        g=0;
        --n;
    }
    if(m==0){
        if((n&1)==(g^1)) puts("1");
        else puts("0");
        return 0;
    }

        
    lint cur,nxt;
    if(m==1) cur=0;
    else cur=1;
    
    lint C=1+m;
    for(int i=1;i<=n;++i){
        nxt=(C-cur+mod)%mod;//nxt=C(i+m,i)-cur;
        cur=nxt;
        C=C*(i+m+1)%mod;
        C=C*invmod(i+1)%mod;
    }

    cout<<cur<<endl;

    
    return 0;
}