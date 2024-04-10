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
int n,m;
int a[50005];
int L[50005],R[50005];
lint same(){
	sort(L,L+n);
	sort(R,R+n);
	int begin=0,end=0;
	lint res=0;
	REP(i,n){
		while(begin<n && R[begin]<L[i]) ++begin;
		while(end<n && R[end]<=L[i]) ++end;
		res+=end-begin;
	}
	return res;
}

lint count1(int k,int x){
	REP(i,n){
		L[i]=(a[i]>>k);
		R[i]=((a[i]>>k)^x);
	}
	lint res=same();
	res/=2;
	return res;
}
lint count2(int k,int x,int k2){
	REP(i,n){
		L[i]=(a[i]>>k);
		R[i]=((a[i]>>k)^x);
		if(a[i]>>k2&1) L[i]|=1<<30;
		else R[i]|=1<<30;
	}
	lint res=same();
	res/=2;
	return res;
}

int main(){
	cin>>n>>m;
	REP(i,n) cin>>a[i];
	
	int x=0;
	lint res=0;
	for(int i=29;i>=0;--i){
		lint match=count1(i,x*2+1);
		if(match>=m){
			x=x*2+1;
		}else{
			res+=match*(lint)(x*2+1)*(1ll<<i);
			REP(j,i) res+=count2(i,x*2+1,j)*(1ll<<j);
			x=x*2;
			m-=match;
		}
	}
	res+=m*(lint)x;
	cout<<res%1000000007<<endl;

	return 0;
}