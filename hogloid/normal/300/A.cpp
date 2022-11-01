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
vector<int> posi,nega,zero;
void print(vector<int>& a){
	REP(i,a.size()) printf(" %d",a[i]);
}

int main(){
	int n;
	cin>>n;
	REP(i,n){
		int a;cin>>a;
		if(a<0) nega.pb(a);
		else if(a>0) posi.pb(a);
		else zero.pb(a);
	}

	printf("1 %d\n",nega.back());
	nega.pop_back();
	if(posi.empty()){
		printf("2 %d %d\n",nega.back(),nega[nega.size()-2]);
		nega.pop_back();
		nega.pop_back();
	}else{
		printf("1 %d\n",posi.back());
		posi.pop_back();
	}

	printf("%d",zero.size()+posi.size()+nega.size());
	print(posi);
	print(nega);
	print(zero);
	putchar('\n');

	return 0;
}