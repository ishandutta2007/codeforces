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
lint ar[100005];
int used[100005];
int main(){
	cin>>n>>k;
	REP(i,n) cin>>ar[i];

	if(k==1){
		printf("%d\n",n);
		return 0;
	}


	sort(ar,ar+n);
	
	int res=0;
	REP(i,n) if(!used[i]){
		lint cur=ar[i];
		int cnt=0;
		while(binary_search(ar,ar+n,cur)){
			int p=lower_bound(ar,ar+n,cur)-ar;

			used[p]=1;
			++cnt;
			cur*=k;
		}
		res+=(cnt+1)/2;
	}
	printf("%d\n",res);


	return 0;
}