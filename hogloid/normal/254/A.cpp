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
pi ar[600005];
int prev[600005];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	REP(i,n*2) scanf("%d",&ar[i].fr),ar[i].sc=i,prev[i]=ar[i].fr;
	
	sort(ar,ar+n*2);
	int ok=1;
	REP(i,n) if(ar[i*2].fr!=ar[i*2+1].fr) ok=0;
	if(!ok){
		puts("-1");
		return 0;
	}


	REP(i,n){
		printf("%d %d\n",ar[i*2].sc+1,ar[i*2+1].sc+1);
	}


	return 0;
}