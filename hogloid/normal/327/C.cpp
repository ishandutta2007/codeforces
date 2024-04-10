#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
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

char s[100005];

const lint mod=1000000007;

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
	scanf("%s",s);
	int k;cin>>k;
	int len=strlen(s);
	
	lint r=0;
	REP(i,len) if(s[i]=='5' || s[i]=='0'){
		r=(r+mpow(2,i))%mod;
	}

	lint L=mpow(2,len);
	lint res;
	if(L!=1) res=r*(mpow(L,k)-1+mod)%mod*mpow(L-1,mod-2)%mod;
	else res=r*k%mod;

	cout<<res<<endl;

	return 0;
}