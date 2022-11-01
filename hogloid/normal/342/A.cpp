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
int appear[10];
vector<vector<int> > res;
typedef vector<int> vi;
int main(){
	cin>>n;
	REP(i,n){
		int t;cin>>t;
		appear[t]++;
	}

	if(appear[7] || appear[5]){
		puts("-1");return 0;
	}
	int four=min(appear[4],min(appear[2],appear[1]));
	if(four<appear[4]){
		puts("-1");return 0;
	}
	appear[2]-=four;appear[1]-=four;

	if(appear[6]!=appear[2]+appear[3] || appear[6]!=appear[1]) {
		puts("-1");return 0;
	}
	int two=appear[2],thr=appear[3];


	REP(hoge,four) puts("1 2 4");
	REP(hoge,two) puts("1 2 6");
	REP(hoge,thr) puts("1 3 6");
	return 0;
}