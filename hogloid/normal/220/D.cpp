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
lint w,h;
lint point[2][2];
const lint mod=1e9+7;
int main(){
	cin>>w>>h;++w;++h;
	REP(i,h) REP(j,w) ++point[i%2][j%2];
	
	lint res=0;
	lint sub=0;
	REP(i,2) REP(j,2) REP(i2,2) REP(j2,2) REP(i3,2) REP(j3,2){
		int x1=j2-j,y1=i2-i,x2=j3-j,y2=i3-i;
		if(abs(x1*y2-y1*x2)%2==0){
			res+=point[i][j]*point[i2][j2]%mod*point[i3][j3]%mod;
			res%=mod;
		}
	}
	sub=w*h;
	sub=(sub+w*h*3*(w*h-1)%mod)%mod;

	sub=(sub+w*h*(w-1)%mod*(w-2)%mod+w*h*(h-1)%mod*(h-2)%mod)%mod;
	
	REPN(i,h,1) REPN(j,w,1){
		sub=(sub+(__gcd(i,j)-1)*2%mod*(h-i)%mod*(w-j)%mod*6%mod)%mod;
	}
	res-=sub%mod;
	res=(res+mod)%mod;
	cout<<res<<endl;



	return 0;
}