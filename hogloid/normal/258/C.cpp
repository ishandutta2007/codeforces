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
int n;
const lint mod=1000000007;
int a[100005];
int factor[1000],factor2[1000];
int pos[1000];
lint mpow(lint a,lint k){
	lint res=1;
	while(k){
		if(k&1) res=(res*a)%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}
lint getval(int cnt){
	if(cnt==0) return 0;
	lint cur=1;
	REP(j,cnt){
		int num=pos[j+1]-pos[j];
		cur=(cur*mpow(j+1,num))%mod;
	}
	return cur;
}
int main(){
	cin>>n;
	REP(i,n) scanf("%d",&a[i]);
	sort(a,a+n);

	lint res=0;
	for(int i=100000;i>=1;--i) {
		int cnt=0,cnt2=0;
		for(int j=1;j*j<=i;++j) if(i%j==0){
			factor[cnt++]=j;
			if(j*j!=i) factor2[cnt2++]=i/j;
		}
		for(int j=cnt2-1;j>=0;--j) factor[cnt++]=factor2[j];
		
		REP(j,cnt){
			pos[j]=lower_bound(a,a+n,factor[j])-a;
		}
		pos[cnt]=n;

		lint tmp=getval(cnt);
		pos[cnt-1]=n;
		tmp=(tmp-getval(cnt-1)+mod)%mod;
		res=(res+tmp)%mod;
	}
	cout<<res<<endl;

	return 0;
}