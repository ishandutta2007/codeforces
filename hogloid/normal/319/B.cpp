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

int n;
int ar[100005];

list<int> incr[100005];

bool judge(const list<int>&l){
	return l.empty();
}

int main(){
	cin>>n;
	REP(i,n) cin>>ar[i];
	

	int m=0;
	REP(i,n){
		int j=i+1;
		while(j<n && ar[j-1]<ar[j]) ++j;

		REPN(k,j,i) incr[m].pb(ar[k]);
		++m;
		i=j-1;
	}
	
	int time=0;
	while(m>1){
		++time;
		REP(i,m-1){
			incr[i+1].pop_front();
		}
		REP(i,m) if(!incr[i].empty()){
			int j=i+1;
			while(j<m && (incr[j].empty() || incr[i].back()<incr[j].front())){
				incr[i].splice(incr[i].end(),incr[j]);
				++j;
			}
			i=j-1;
		}
		m=remove_if(incr,incr+m,judge)-incr;
	}

	printf("%d\n",time);


	return 0;
}