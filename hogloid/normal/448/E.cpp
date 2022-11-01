#define DEB

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
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

lint x;
lint k;
int MX=100000;
lint res[100005];
int cnt;


vector<lint> divs;

lint prime[30];
int cnt2;

void push(lint a){
	res[cnt++]=a;
	if(cnt>=MX){
		REP(i,cnt) cout<<res[i]<<' ';
		cout<<endl;
		exit(0);
	}
}

void dfs(lint x,lint k){
	if(k==0){
		push(x);
		return;
	}
	if(x==1){
		push(x);
		return;
	}
	if(binary_search(prime,prime+cnt2,x)){
		for(int i=0;i<k;++i) push(1);
		push(x);
		return;
	}
	REP(i,divs.size()) if(x%divs[i]==0){
		dfs(divs[i],k-1);
	}
}
int main(){
	cin>>x>>k;
	
	if(x==1){
		puts("1");
		return 0;
	}
	for(lint i=2;i*i<=x;++i) if(x%i==0){
		divs.pb(i);
		if(i*i!=x) divs.pb(x/i);
	}
	divs.pb(x);

	divs.pb(1);

	sort(ALL(divs));
	REP(i,divs.size()){
		int flag=0;
		REPN(j,divs.size(),1) if(i!=j && divs[i]%divs[j]==0) flag=1;
		if(!flag) prime[cnt2++]=divs[i];
	}

	dfs(x,k);

	REP(i,cnt) cout<<res[i]<<' ';
	cout<<endl;

	return 0;
}