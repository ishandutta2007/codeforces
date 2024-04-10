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
int n,l,t;
lint pos[4000005];
int main(){
	scanf("%d%d%d",&n,&l,&t);
	REP(i,n){
		int a;scanf("%d",&a);
		pos[i]=a;
	}
	REPN(i,n*4,n) pos[i]=pos[i-n]+l;

	double round=t/l;
	t%=l;

	double res=round*n*(n-1)/2,add=0;

	lint len=t*2ll;
	int j=0;
	REP(i,n){
		while(j<i+n*2 && pos[j]-pos[i]<=len){
			++j;
		}
		add+=j-i-1;
		if(j>i+n) --add;
	}
	add/=4;

	printf("%.10f\n",res+add);

	return 0;
}