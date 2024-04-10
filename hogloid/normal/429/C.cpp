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

int n,m;

int c[25];
int one;

int par[25],rem[25],ch[25];
int k;
bool dfs(int idx){
	if(idx==m){
		REP(i,m) if(ch[i]+rem[i]<2) return false;
		return true;
	}
	REP(i,idx) if(rem[i]>=c[idx]){
		rem[i]-=c[idx];
		par[idx]=i;
		ch[i]++;
		
		rem[idx]=c[idx]-1;
		ch[idx]=0;
		if(dfs(idx+1)) return true;

		--ch[i];
		rem[i]+=c[idx];
	}
	return false;
}
bool solve(){
	cin>>n;
	REP(i,n) cin>>c[i];
	sort(c,c+n,greater<int>());
	m=0;
	REP(i,n) if(c[i]>1) m=i+1;
	if(m==0) {
		return n==1;
	}

	REP(i,m) if(c[i]==2) return false;
	
	int need=0;
	REP(i,m){
		need+=c[i]-1;
		if(i>0) need-=c[i];
	}
	one=n-m;
	if(need!=one) return false;
	dump(m);
	
	k=1;
	rem[0]=c[0]-1;
	par[0]=-1;
	if(dfs(1)) return true;
	return false;
}



int main(){
	puts(solve()?"YES":"NO");

	return 0;
}