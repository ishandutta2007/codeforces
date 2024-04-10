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
int n,k;
int a[2005];
lint C[2005];
const lint mod=1000000007;
lint extgcd(lint a,lint b,lint& x,lint& y){
	lint d=a;
	if(b!=0){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else{
		x=1;y=0;
	}
	return d;
}
lint invmod(lint a){
	lint x,y;
	extgcd(a,mod,x,y);
	return (x%mod+mod)%mod;
}
int main(){

	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d",&a[i]);
	if(k==0){
		REP(i,n) printf("%d%c",a[i],i==n-1?'\n':' ');
		return 0;
	}
	REP(i,n){
		C[i]=1;
		REP(j,i) C[i]=(C[i]*(i+k-1-j)%mod*invmod(j+1)%mod);
	}
	REP(i,n){
		lint sum=0;
		REP(j,i+1){
			sum+=C[i-j]*a[j];
			sum%=mod;
		}
		cout<<sum;
		printf("%c",i==n-1?'\n':' ');
	}
	return 0;
}