#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}

int n;
pi ps[100005];
vector<int> x[100005],y[100005];
int main(){
	cin>>n;
	REP(i,n) scanf("%d%d",&ps[i].fr,&ps[i].sc);
	
	sort(ps,ps+n);
	int res=0;
	for(int i=n-1;i>=0;--i){
		pi p=ps[i];
		if(x[p.fr].size()>y[p.sc].size()){
			REP(j,y[p.sc].size()){
				int dif=y[p.sc][j]-p.fr;
				if(binary_search(ALL(x[p.fr]),p.sc+dif,greater<int>())
						&& binary_search(ps,ps+n,mp(p.fr+dif,p.sc+dif))) ++res;
			}
		}else{
			REP(j,x[p.fr].size()){
				int dif=x[p.fr][j]-p.sc;
				if(binary_search(ALL(y[p.sc]),p.fr+dif,greater<int>()) &&
						binary_search(ps,ps+n,mp(p.fr+dif,p.sc+dif))) ++res;
			}
		}
		x[p.fr].pb(p.sc);
		y[p.sc].pb(p.fr);
		dump(p);dump(res);
	}
	cout<<res<<endl;


	return 0;
}