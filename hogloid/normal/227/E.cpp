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
lint m,l,r,k;
typedef lint item;
typedef vector<item> vec;
typedef vector<vector<item> > mat;
mat matpow(const mat& a,const mat& b){
	int n=a.size();
	mat res(n,vec(n));
	REP(i,n) REP(j,n) REP(k,n){
		res[i][j]+=a[i][k]*b[k][j];
		res[i][j]%=m;
	}
	return res;
}
mat mpow(mat& a,lint k){
	int n=a.size();
	mat res(n,vec(n));
	REP(i,n) res[i][i]=1;
	while(k){
		if(k&1) res=matpow(res,a);
		a=matpow(a,a);
		k>>=1;
	}
	return res;
}
int main(){
	cin>>m>>l>>r>>k;
	--l;
	lint n=r-l+1;
	
	lint p;
	if((r-l)/k<=1e6){
		for(lint i=2e6;i>=0;--i){
			if(r/i-l/i>=k){
				p=i;break;
			}
		}
	}else{
		for(lint i=1;;++i){// within ...r]
			lint wid=r/i;
			if(i-l/wid>=k){
				p=wid;
				break;
			}
		}
	}
			
	mat M(2,vec(2));
	M[0][1]=M[1][0]=M[1][1]=1;
	M=mpow(M,p-1);
	lint res=M[0][0]+M[0][1];
	res%=m;
	cout<<res<<endl;

	return 0;
}