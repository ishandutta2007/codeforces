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
pair<pi,int> range[200005];

bool cmp(const pair<pi,int>& a,const pair<pi,int>& b){
	if(a.fr.fr==b.fr.fr) return a.fr.sc>b.fr.sc;
	return a.fr<b.fr;
}

int mark[200005];
vector<int> unuse;
int main(){
	scanf("%d%d",&n,&m);
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);
		b+=a;
		range[i]=mp(mp(a,b),i);
	}
	sort(range,range+m,cmp);
	
	int maxr=-1;

	int i=0;
	while(i<m){
		mark[i]=1;
		int j=i;
		while(j<m && range[j].fr.fr<=range[i].fr.sc){
			range[j].fr.fr=range[i].fr.sc;
			++j;
		}
		int maxr=-1,who=m;
		for(j=i+1;j<m && range[j].fr.fr==range[i].fr.sc;++j) if(maxr<range[j].fr.sc 
			&& range[j].fr.fr<range[j].fr.sc){
			maxr=range[j].fr.sc;
			who=j;
		}
		if(who==m) who=j;
		i=who;
	}

	REP(i,m) if(!mark[i]) unuse.pb(range[i].sc);

	printf("%d\n",unuse.size());
	REP(i,unuse.size()) printf("%d%c",unuse[i]+1,i==unuse.size()-1?'\n':' ');


	return 0;
}