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
lint k,l,r,p;

lint mpow(lint a,lint k,lint mod){
	lint res=1;
	while(k){
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}
lint inv(lint a){
	return mpow(a,p-2,p);
}

int main(){
	int t;scanf("%d",&t);
	while(t--){
		cin>>k>>l>>r>>p;
		++r;
		
		int odd=(k&1);
		if(k==1) cout<<2%p<<endl;
		else{
			k%=p;

			lint R=(mpow(k,mpow(2,r,p-1)+p-1,p)-1+p)%p,
				L=(mpow(k,mpow(2,l,p-1)+p-1,p)-1+p)%p;

			lint ans;
			if(L==0) ans=mpow(2,r-l,p);
			else{
				L=inv(L);
				ans=L*R%p;
			}
			if(odd) ans=(ans*mpow(inv(2),r-l-1,p))%p;
		
			cout<<ans<<endl;
		}
	}

	return 0;
}