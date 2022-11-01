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
lint n;
pair<lint,int> factor[100];
lint tot[100];
int m=0;
lint ans;
bool f(lint a){
	if(a<=0 || a&1) return true;
	return false;
}

void check(lint a,lint b,lint c){
	if(f(b+c-a) || f(c+a-b) || f(a+b-c));
	else ++ans;
}

void dfs(int d,lint a,lint b,lint c){
	if(d==m){
		check(a,b,c);
		return;
	}
	lint mul1=1;
	REP(i,factor[d].sc+1){
		lint mul2=1;
		REP(j,factor[d].sc+1-i){
			lint mul3=tot[d]/mul1/mul2;
			dfs(d+1,a*mul1,b*mul2,c*mul3);
			mul2*=factor[d].fr;
		}
		mul1*=factor[d].fr;
	}
}
int main(){
	cin>>n;

	if(n%3){
		puts("0");
		return 0;
	}
	n/=3;


	lint t=n;

	for(lint i=2;i*i<=t;++i) if(t%i==0){
		factor[m].fr=i;
		lint tmp=1;
		while(t%i==0){
			t/=i;
			tmp*=i;
			factor[m].sc++;
		}
		tot[m]=tmp;
		++m;
	}
	if(t>1) factor[m++]=mp(t,1),tot[m-1]=t;;

	dfs(0,1,1,1);

	cout<<ans<<endl;



	return 0;
}