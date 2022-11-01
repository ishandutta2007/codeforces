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

lint n,m,k;
const lint mod=1000000009;

lint mpow(lint a,lint k){
	lint res=1;
	while(k>0){
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}

int main(){
	cin>>n>>m>>k;
	lint rest=n-m;
	lint nodoub=rest*(k-1);
	if(nodoub+k-1>=m){
		cout<<m<<endl;
		return 0;
	}
	lint mrest=m-nodoub;
	lint block=mrest/k,rest2=mrest%k;
	lint res=(mpow(2,block)-1+mod)*2%mod*k%mod
		+rest2+nodoub;
	res%=mod;
	cout<<res<<endl;


	return 0;
}