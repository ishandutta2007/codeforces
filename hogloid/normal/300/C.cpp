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
int a,b,n;

lint mod=1000000007;

bool isexc(int r){
	while(r>0){
		if(r%10!=a && r%10!=b) return false;
		r/=10;
	}
	return true;
}

lint mpow(lint a,lint k){
	lint res=1;
	while(k){
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}


int main(){
	cin>>a>>b>>n;
	
	int sum=a*n;
	lint C=1;
	lint res=0;
	
	REP(i,n+1){
		if(isexc(sum)){
			res+=C;
			res%=mod;
		}

		C=C*(n-i)%mod*mpow(i+1,mod-2)%mod;
		sum+=b-a;
	}

	cout<<res<<endl;
	



	return 0;
}