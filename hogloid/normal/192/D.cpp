#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
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
priority_queue<lint,vector<lint>,greater<lint> > pq;
int main(){
	cin>>n>>k;
	lint b;cin>>b;
	REP(i,n) cin>>ar[i];
	lint sum=0;
	int ans=n-1;
	for(int i=n-2;i>=0;--i){
		if(sum+ar[i]>b) ans=min(ans,i);
		sum+=ar[i];
		pq.push(ar[i]);
		while(pq.size()>=k){
			sum-=pq.top();pq.pop();
		}
	}
	cout<<ans+1<<endl;
	return 0;
}