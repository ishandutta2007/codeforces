#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
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
pi card[100005];
int kind[200005];
pi state[200005];
int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&card[i].fr,&card[i].sc);
	REP(i,n) kind[i]=card[i].fr,kind[i+n]=card[i].sc;
	sort(kind,kind+n*2);
	int kn=unique(kind,kind+n*2)-kind;
	REP(i,n){
		card[i].fr=lower_bound(kind,kind+kn,card[i].fr)-kind;
		card[i].sc=lower_bound(kind,kind+kn,card[i].sc)-kind;

		state[card[i].fr].fr++;
		if(card[i].fr!=card[i].sc) state[card[i].sc].sc++;
	}
	int res=INF,half=(n+1)/2;
	REP(i,kn) if(state[i].fr+state[i].sc>=half){
		res=min(res,max(0,half-state[i].fr));
	}
	if(res==INF) res=-1;
	printf("%d\n",res);
	return 0;
}