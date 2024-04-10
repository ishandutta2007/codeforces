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
int ar[100005];
pi ar2[100005];
pi stk[100005];
int larger[100005];
int solve(){
	REP(i,n) ar2[i]=mp(ar[i],i);
	REP(i,n+1) stk[i]=mp(-1,-1);
	int m=0;
	REP(i,n){
		int lb=0,ub=m;
		while(ub-lb>1){
			int md=(lb+ub)>>1;
			if(stk[md].fr<ar[i]) ub=md;
			else lb=md;
		}
		if(stk[lb].fr>ar[i]) larger[i]=stk[lb].sc;
		else larger[i]=-1;

		while(m>0 && stk[m-1].fr<ar[i]) --m;
		stk[m++]=mp(ar[i],i);
	}
	sort(ar2,ar2+n,greater<pi>());
	
	int ans=0;
	REP(i,n){
		int cur=ar2[i].sc-1;
		while(cur>=0){
			if(ar[cur]>ar2[i].fr) break;
			ans=max(ans,ar[cur]^ar2[i].fr);
			cur=larger[cur];
		}
	}

	return ans;
}



int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&ar[i]);
	
	int ans=solve();
	reverse(ar,ar+n);
	ans=max(ans,solve());

	cout<<ans<<endl;

	return 0;
}