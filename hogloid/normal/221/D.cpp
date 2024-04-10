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
int n,m;
int a[100005];
pi query[100005];
pair<pi,pi> event[100005];
int zip[100005];
int B=300;
int sum[100005];
int ans[100005];
int brute(int s,int t){
	int match=0;
	REPN(i,t,s){
		if(sum[a[i]]==zip[a[i]]) --match;
		sum[a[i]]++;
		if(sum[a[i]]==zip[a[i]]) ++match;
	}
	int res=match;
	REPN(i,t,s){
		--sum[a[i]];
	}
	return res;
}
int main(){
	cin>>n>>m;
	REP(i,n) scanf("%d",&a[i]),zip[i]=a[i];
	sort(zip,zip+n);
	int zn=unique(zip,zip+n)-zip;
	REP(i,n) a[i]=lower_bound(zip,zip+zn,a[i])-zip;

	REP(i,m) scanf("%d%d",&query[i].fr,&query[i].sc),--query[i].fr;
	REP(i,m){
		if(query[i].sc-query[i].fr>=B+2) event[i]=mp(mp((query[i].fr+B-1)/B*B,query[i].sc),mp(query[i].fr,i));
		else ans[i]=brute(query[i].fr,query[i].sc),event[i]=mp(mp(-1,-1),mp(-1,-1));
	}
	sort(event,event+m);
	int back=0;
	int match=0;
	int j=0;
	REP(i,m){
		pair<pi,pi>& e=event[i];
		if(e.fr.fr==-1) continue;
		if(back!=e.fr.fr){
			REP(i,zn) sum[i]=0;
			match=0;
			back=e.fr.fr;j=e.fr.fr;
		}
		while(j<e.fr.sc){
			if(sum[a[j]]==zip[a[j]]) --match;
			++sum[a[j]];
			if(sum[a[j]]==zip[a[j]]) ++match;
			++j;
		}
		ans[e.sc.sc]=match+brute(e.sc.fr,back);
	}
	REP(i,m) printf("%d\n",ans[i]);
	return 0;
}