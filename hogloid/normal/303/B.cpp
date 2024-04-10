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
typedef pair<lint,lint> pi;
lint n,m,x,y,a,b;

pair<lint,pair<pi,pi> > ans;

bool solve(lint len){
	lint l=x-(a*len+1)/2,r=l+a*len,
		bot=y-(b*len+1)/2,t=bot+b*len;
	
	if(l<0){
		r+=-l;
		l=0;
	}
	if(bot<0){
		t+=-bot;
		bot=0;
	}
	if(r>n){
		l-=r-n;
		r=n;
	}
	if(t>m){
		bot-=t-m;
		t=m;
	}

	if(l<0 || bot<0) return false;

	ans=mp(0,mp(mp(l,bot),mp(r,t)));
	return true;
}

int main(){
	cin>>n>>m>>x>>y>>a>>b;

	lint g=__gcd(a,b);
	a/=g;
	b/=g;
	

	lint lb=0,ub=1000000010;
	while(ub-lb>1){
		lint md=(lb+ub)>>1;
		if(solve(md)) lb=md;
		else ub=md;
	}

	cout<<ans.sc.fr.fr<<' '<<ans.sc.fr.sc<<' '<<ans.sc.sc.fr<<' '<<ans.sc.sc.sc<<endl;

	return 0;
}