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
int com[100005];
int main(){
	cin>>n;
	REP(i,n) cin>>com[i];

	REP(i,n){
		int j=i;

		vector<pi> num;
		while(j<n && com[j]!=0){
			num.pb(mp(com[j],j));
			++j;
		}
		sort(ALL(num));
		reverse(ALL(num));

		REP(t,3) num.pb(mp(-INF,-INF));
		int a=num[0].sc,b=num[1].sc,c=num[2].sc;

		REPN(k,j,i){
			if(k==a) puts("pushStack");
			else if(k==b) puts("pushQueue");
			else if(k==c) puts("pushFront");
			else puts("pushBack");
		}
		if(j<n) {
		if(a==-INF) puts("0");
		else if(b==-INF) puts("1 popStack");
		else if(c==-INF) puts("2 popStack popQueue");
		else puts("3 popStack popQueue popFront");
		}
		i=j;
	}

	return 0;
}