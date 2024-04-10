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
lint n,x;

bool isprime(lint a){
	for(lint i=2;i*i<=a;++i) if(a%i==0) return false;
	return true;
}

lint mpow(lint a,lint k,lint mod){
	lint res=1;
	while(k){
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}

int main(){
	cin>>n>>x;
	if(!isprime(n+1)){
		puts("-1");
		return 0;
	}

	for(int i=x-1;i>=2;--i) if(__gcd((lint)i,n+1)==1){
		int fail=0;
		lint cur=1;
		REP(j,n-1){
			cur=cur*i%(n+1);
			if(cur==1){
				fail=1;break;
			}
		}
		if(!fail){
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");

	return 0;
}