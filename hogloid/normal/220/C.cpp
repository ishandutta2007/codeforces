#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
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
int a[100005],b[100005],reva[100005],revb[100005];
multiset<int> s;
int srch(int k){
	int res=INF;
	multiset<int>::iterator it=s.lower_bound(k);
	if(it!=s.end()) res=(*it)-k;
	if(it!=s.begin()){
		--it;
		res=min(res,k-(*it));
	}
	return res;
}
int main(){
	cin>>n;
	REP(i,n) scanf("%d",&a[i]),--a[i],reva[a[i]]=i;
	REP(i,n) scanf("%d",&b[i]),--b[i],revb[b[i]]=i;
	REP(i,n) s.insert(reva[i]-revb[i]);
	REP(i,n){
		int tmp=srch(-i);
		s.erase(s.find(reva[b[i]]-i));
		s.insert(reva[b[i]]-i-n);
		printf("%d\n",tmp);
	}

	return 0;
}