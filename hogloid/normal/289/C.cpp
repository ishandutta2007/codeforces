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
int n,k;

char ans[1000005];
int main(){
	cin>>n>>k;
	
	if(n<k || (k==1 && n>1)){
		puts("-1");
		return 0;
	}
	if(k==1){
		puts("a");
		return 0;
	}


	int rest=n-k;
	REP(i,rest/2){
		ans[i*2]='a';
		ans[i*2+1]='b';
	}

	if(rest&1){
		ans[rest-1]='a';
		ans[rest]='b';
		ans[rest+1]='a';

		for(int i=2;i<k;++i) ans[rest+i]='a'+i;
		
	}else{

		REP(i,k) ans[rest+i]='a'+i;
	}



	ans[n]='\0';
	printf("%s\n",ans);


	return 0;
}