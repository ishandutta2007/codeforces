#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
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
int ball2[100005];
int num;
int res[100005][3];
int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&ball2[i]);
	sort(ball2,ball2+n);
	priority_queue<pi> pq;
	REP(i,n){
		int j=i;
		while(j<n && ball2[j]==ball2[i]) ++j;
		pq.push(mp(j-i,ball2[i]));
		i=j-1;
	}
	num=0;
	while(pq.size()>=3){
		pi a[3];
		REP(i,3){
			a[i]=pq.top();pq.pop();
			res[num][i]=a[i].sc;
			--a[i].fr;
		}
		sort(res[num],res[num]+3);
		REP(i,3) if(a[i].fr>0) pq.push(a[i]);
		++num;
	}
	
	printf("%d\n",num);
	REP(i,num) REP(j,3) printf("%d%c",res[i][2-j],j==2?'\n':' ');
	return 0;
}