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

int n,x;
int ar[100005];

int cnt[100];

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
	cin>>n>>x;
	REP(i,n) cin>>ar[i];

	lint expo=0;
	int maxi=0;
	lint sum=0;

	REP(i,n) sum+=ar[i],maxi=max(maxi,ar[i]);
	
	expo=sum-maxi;
	REP(i,n){
		ar[i]=maxi-ar[i];

		if(ar[i]<100) ++cnt[ar[i]];
	}
	
	int reach;
	REP(i,80){
		reach=i;
		if(cnt[i]%x==0){
			cnt[i+1]+=cnt[i]/x;
		}else if(cnt[i]){
			break;
		}
	}
	expo+=reach;
	
	expo=min(expo,sum);
	cout<<mpow(x,expo)<<endl;




	return 0;
}