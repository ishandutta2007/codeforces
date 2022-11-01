#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<list>
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
int n,m;
int a[100005],b[100005];
int done[100005];

vector<int> res;
int main(){
	cin>>n>>m;
	REP(i,n) cin>>a[i];
	REP(i,n) cin>>b[i];

	sort(a,a+n);
	sort(b,b+n);
	
	list<int> A,B;
	REP(i,n) A.pb(a[i]);
	REP(i,n) B.pb(b[i]);

	list<int>::iterator it=A.end(),it2=B.begin();
	do{
		--it;
		while(*it2+*it<=m-1) ++it2;

		if(it2!=B.begin()){
			--it2;
			res.pb(*it2+*it);
			it2=B.erase(it2);
			it=A.erase(it);
		}
	}while(it!=A.begin());

	it=A.end();it2=B.end();

	do{
		--it;
		--it2;
		res.pb((*it+*it2)%m);
	}while(it!=A.begin());

	sort(ALL(res),greater<int>());
	REP(i,n) printf("%d\n",res[i]);
	


	return 0;
}