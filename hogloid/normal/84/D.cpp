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
lint k;
lint ar[100005];

pair<lint,lint> ar2[100005];
int main(){
	cin>>n>>k;
	REP(i,n){
		cin>>ar[i];
		ar2[i]=mp(ar[i],i);
	}
	sort(ar2,ar2+n);
	
	lint cost=0,prev=0;
	REP(i,n){
		cost+=(ar2[i].fr-prev)*(n-i);
		if(cost>=k){
			cost-=(ar2[i].fr-prev)*(lint)(n-i);
			lint rest=k-cost;
			lint decr=rest/(n-i);
			REP(j,n) ar[j]-=decr+prev;
			lint rest2=rest-decr*(n-i);
			int pos=0;
			for(int j=0;rest2>0;++j) if(ar[j]>0){
				--ar[j];
				--rest2;
				pos=j+1;
			}
			vector<int> res;
			REP(j,n){
				int p=(pos+j)%n;
				if(ar[p]>0) res.pb(p);
			}
			REP(j,res.size()) printf("%d\n",res[j]+1);
			return 0;
		}
		prev=ar2[i].fr;
	}
	puts("-1");







	return 0;
}