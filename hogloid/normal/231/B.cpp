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
int main(){
	int n,d,l;cin>>n>>d>>l;
	int elem_even=n/2,elem_odd=n-elem_even;

	int sum_even=elem_even,sum_odd=elem_odd;
	
	vector<int> seq;
	if(sum_odd-sum_even>d){
		sum_even=sum_odd-d;
		if(sum_even>elem_even*l){
			puts("-1");
			return 0;
		}
	}else{
		sum_odd=d+sum_even;
		if(sum_odd>elem_odd*l){
			puts("-1");
			return 0;
		}
	}

	sum_even-=elem_even;
	sum_odd-=elem_odd;

	REP(i,n){
		if((i+1)%2==0){
			seq.pb(min(sum_even,l-1)+1);
			sum_even-=min(sum_even,l-1);
		}else{
			seq.pb(min(sum_odd,l-1)+1);
			sum_odd-=min(sum_odd,l-1);
		}
	}
	REP(i,n) printf("%d%c",seq[i],i==n-1?'\n':' ');




	return 0;
}