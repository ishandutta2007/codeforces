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
int ar[100005],where[100005];
int kind[100005];
pi ar2[100005];
int isluck(int a){
	while(a>0){
		if(a%10!=7 && a%10!=4) return false;
		a/=10;
	}
	return true;
}

vector<pi> ope;

void swp(int a,int b){
	if(a==b) return;
	ope.pb(mp(a,b));
	swap(where[ar[a]],where[ar[b]]);
	swap(ar[a],ar[b]);
	swap(kind[a],kind[b]);
}

int main(){
	scanf("%d",&n);
	
	REP(i,n){
		scanf("%d",&ar[i]);
		kind[i]=isluck(ar[i]);
		ar2[i]=mp(ar[i],i);
	}
	int fail=0;
	REP(i,n-1) if(ar[i]>ar[i+1]) fail=1;

	if(!fail){
		puts("0");
		return 0;
	}


	sort(ar2,ar2+n);

	REP(i,n) ar[ar2[i].sc]=i;

	REP(i,n) where[ar[i]]=i;
	int pivot=-1,val;
	REP(i,n) if(kind[i]){
		pivot=i;
		val=ar[pivot];
	}
	if(pivot==-1){
		puts("-1");
		return 0;
	}
	REP(i,val){
		if(ar[i]!=i){
			swp(pivot,i);
			pivot=i;
			
			int tmp=where[i];
			swp(where[i],pivot);
			pivot=tmp;

		}
	}
	for(int i=n-1;i>val;--i) if(ar[i]!=i){
		swp(pivot,i);
		pivot=i;

		int tmp=where[i];
		swp(where[i],pivot);
		pivot=tmp;
	}


	printf("%d\n",ope.size());
	REP(i,ope.size()) printf("%d %d\n",ope[i].fr+1,ope[i].sc+1);





	return 0;
}