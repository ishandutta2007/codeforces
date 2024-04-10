#include <string>
#include <vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<numeric>
#include<list>
#include<cstdio>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#define REP(num,num2) for(int num=0;num<(int)num2;++num)
#define REPN(num,num2,init) for(int num=init;num<(int)num2;++num)
#define ITR(x) __typeof((x).begin())
#define FOR(itr,data) for(ITR(data) itr=(data).begin();itr!=(data).end();++itr)
#define ALL(typ) (typ).begin(),(typ).end()
#define SPR(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz .size()
#define INF ((int)1e9)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
typedef long long int lint;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pair<int,int> > vp;
typedef pair<int,int> pi;
const double PI  = acos(-1.0);
template<class T> void debug(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
int k,n;
int pen[1005];
pi stool[1005];
int main(){
	scanf("%d%d",&n,&k);
	int cnt=0,cnt2=0,mini=INF;
	double res=0;
	REP(i,n){
		int a,t;
		scanf("%d%d",&a,&t);
		chmin(mini,a);
		if(t==1) stool[cnt++]=mp(a,i+1);
		else{
			res+=a;
			pen[cnt2++]=i+1;
		}
	}
	sort(stool,stool+cnt,greater<pi>());
	if(cnt<k){
		REP(i,cnt){
			res+=stool[i].fr/2.0;
		}
	}else{
		REP(i,k-1) res+=stool[i].fr/2.0;
		REPN(i,cnt,k-1) res+=stool[i].fr;
		res-=mini/2.0;
	}
	printf("%.1f\n",res);
	
	if(cnt<k){
		REP(i,cnt) printf("%d %d\n",1,stool[i].sc);
		k-=cnt;
		int i=0;
		while(k>1){
			printf("%d %d\n",1,pen[i++]);
			--k;
		}
		printf("%d",cnt2-i);
		for(;i<cnt2;++i) printf(" %d",pen[i]);
		putchar('\n');
	}else{
		REP(i,k-1) printf("%d %d\n",1,stool[i].sc);
		printf("%d",n-(k-1));
		REPN(i,cnt,k-1) printf(" %d",stool[i].sc);
		REP(i,cnt2) printf(" %d",pen[i]);
		putchar('\n');
	}
	/*

	--k;
	int i;
	for(i=0;k>0 && cnt>0;++i,--k,--cnt){
		printf("%d %d\n",1,stool[i].sc);
	}
	if(k==0){
		printf("%d",cnt+cnt2);
		for(;cnt>0;++i,--cnt) printf(" %d",stool[i].sc);
		REP(j,cnt2) printf(" %d",pen[j]);
		putchar('\n');
	}else{
		int j=0;
		while(k>0){
			--k;
			printf("%d %d\n",1,pen[j]);
			++j;
		}
		printf("%d",cnt2-j);
		for(j;j<cnt2;++j) printf(" %d",pen[j]);
		putchar('\n');
	}
	*/
	return 0;
}