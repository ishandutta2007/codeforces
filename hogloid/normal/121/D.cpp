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
const lint LRG=2e18;
lint luck[1000000];
int cnt;
int n;
lint k;
pair<lint,lint> range[100005];

lint end[100005],begin[100005];
lint costR[1000005],costL[1000005];
inline lint mlt(lint a,lint b){
	double res=a*(double)b;
	if(res>LRG) return LRG;
	return a*b;
}
inline void add(lint& a,lint b){
	a=min(a+b,LRG);
}
lint minlen;
bool check(lint len){
	REP(i,cnt-len+1){
		if(luck[i+len-1]-luck[i]>minlen) continue;
		lint cost=costR[i+len-1]+costL[i];
		if(cost<=k) return true;
	}
	return false;
}
int main(){
	for(int i=1;i<=18;++i){
		REP(j,1<<i){
			lint num=0;
			REP(k,i) num=num*10+(j>>k&1?7:4);
			luck[cnt++]=num;
		}
	}
	sort(luck,luck+cnt);

	cin>>n>>k;
	
	minlen=2e18;
	REP(i,n){
		cin>>range[i].fr>>range[i].sc;
		minlen=min(minlen,range[i].sc-range[i].fr);
		end[i]=range[i].sc;
		begin[i]=range[i].fr;
	}
	sort(end,end+n);
	sort(begin,begin+n);
	
	int j=0;

	REP(i,cnt){
		if(j) add(costR[i],mlt(j,(luck[i]-luck[i-1])));
		while(j<n && end[j]<luck[i]) add(costR[i],luck[i]-end[j]),++j;
		
		costR[i+1]=costR[i];
	}
	
	costL[cnt-1]=0;
	j=n-1;
	for(int i=cnt-1;i>=0;--i){
		add(costL[i],mlt((n-j-1),(luck[i+1]-luck[i])));
		while(j>=0 && begin[j]>luck[i]) add(costL[i],begin[j]-luck[i]),--j;
		if(i) costL[i-1]=costL[i];
	}
	
	lint lb=0,ub=cnt+1;
	while(ub-lb>1){
		lint md=(lb+ub)>>1;
		if(check(md)) lb=md;
		else ub=md;
	}
	cout<<lb<<endl;
	return 0;
}