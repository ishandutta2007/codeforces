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
int n,t;
int ar[200005];
int main(){
	cin>>n>>t;
	REP(i,n) cin>>ar[i];
	REP(i,n) ar[i+n]=ar[i];

	int res=0,sum=0;
	int j=0;
	REP(i,n){
		while(sum+ar[j]<=t && j<n){
			sum+=ar[j];
			++j;
		}
		res=max(res,j-i);
		sum-=ar[i];
	}
	printf("%d\n",res);



	return 0;
}