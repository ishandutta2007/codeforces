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
lint s,k;
lint seq[1005],sum[1005];
int main(){
	cin>>s>>k;

	seq[0]=1;
	sum[1]=1;
	int n=1;
	while(seq[n-1]<=s){
		seq[n]=sum[n]-sum[max(0ll,n-k)];n++;
		sum[n]=sum[n-1]+seq[n-1];
	}

	vector<int> res;
	int flag=0;
	while(s>0){
		int p;
		p=upper_bound(seq,seq+n,s)-seq;--p;
		flag=1;
		res.pb(seq[p]);
		s-=seq[p];
	}
	if(res.size()==1) res.pb(0);
	cout<<res.size()<<endl;
	REP(i,res.size()) printf("%d\n",res[i]);

	return 0;
}