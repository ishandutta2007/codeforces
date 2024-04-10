#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
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
int n,m,k;
multiset<int> all;
int ar[100005],ar2[100005];
int main(){
	cin>>n>>m>>k;
	REP(i,n){
		scanf("%d",&ar[i]);
		all.insert(ar[i]);
	}

	REP(i,m) scanf("%d",&ar2[i]);
	sort(ar,ar+n);
	sort(ar2,ar2+m);

	for(int i=m-1;i>=0;--i){
		multiset<int>::iterator it=all.upper_bound(ar2[i]);
		if(it!=all.begin()){
			--it;
			all.erase(it);
		}
	}
	if(all.size()) puts("YES");
	else puts("NO");



	return 0;
}