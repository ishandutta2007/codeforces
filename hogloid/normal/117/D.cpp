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
lint n,m,mod;


lint calc(lint a,lint b){
	if(a%2==0) return (a/2)%mod*(b%mod)%mod;
	return a%mod*((b/2)%mod)%mod;
}
lint floor(lint a,lint b){
	if(a>=0) return a/b;
	if(a%b==0) return a/b;
	return a/b-1;
}
lint solve(lint L,lint R,lint l,lint r,lint low,lint up,lint C,lint dif){
	if(l<=L && R<=r){
		lint begin=floor(low-C+dif-1,dif),end=floor(up-1-C,dif);
		begin=max(begin,0ll);

		end=min(end,R-L-1);
		++end;
		if(begin>=end) return 0;
		//[begin...end)
		lint len=end-begin;
		lint ans=(len+C%mod*(len%mod)%mod+(calc(begin+end-1,len)%mod*(dif%mod)%mod))%mod;
		return ans;
	}else if(r<=L || R<=l) return 0;

	lint md=(L+R+1)>>1;
	lint A=solve(L,md,l,r,low,up,C,dif*2);
	lint B=solve(md,R,l,r,low,up,C+dif,dif*2);
	return (A+B)%mod;
}

int main(){
	cin>>n>>m>>mod;

	REP(hoge,m){
		lint l,r,u,v;
		cin>>l>>r>>u>>v;
		--l;
		--u;
		cout<<solve(0,n,l,r,u,v,0,1)<<endl;
	}

	return 0;
}