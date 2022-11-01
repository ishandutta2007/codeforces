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
int main(){
	int a=-1,b=-1;
	cin>>n;
	int res=1,cur=0;
	REP(i,n){
		int ta,tb;cin>>ta>>tb;
		if(mp(a,b)==mp(ta,tb)){
			++cur;
			res=max(res,cur);
		}else{
			cur=1;
			a=ta;
			b=tb;
		}
	}
	cout<<res<<endl;


	return 0;
}