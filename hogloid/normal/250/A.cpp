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
int a[105];
vector<int> res;
int main(){
	cin>>n;
	REP(i,n) cin>>a[i];
	int sum=0,j=0;
	REP(i,n){
		j=i;
		sum=(a[i]<0?1:0);
		while(j<n && sum<3){
			++j;
			if(a[j]<0) ++sum;
		}
		res.pb(j-i);
		i=j-1;
	}
	cout<<res.size()<<endl;
	REP(i,res.size()) printf("%d\n",res[i]);

	return 0;
}