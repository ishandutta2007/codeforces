
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<string>

#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}

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



const int INF=5e8;
	
struct segtree{
	pi val[2200000],maxi[2200000];
	int add[2200000];
	int n;
	void init(int n_,int* ar){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2){
			val[i]=mp(INF,-1);
			maxi[i]=mp(-INF,-1);
		}
		REP(i,n_) val[i+n-1]=maxi[i+n-1]=mp(ar[i],i);

		for(int i=n-2;i>=0;--i){
			val[i]=min(val[i*2+1],val[i*2+2]);

			if(maxi[i*2+1].fr>=maxi[i*2+2].fr) maxi[i]=maxi[i*2+1];
			else maxi[i]=maxi[i*2+2];
		}
	}
	void add2(int a,int i,int l,int r){
		if(a<=l) {
			++add[i];
			++val[i].fr;
			++maxi[i].fr;
			return;
		}
		if(r<=a) return;
		int md=(l+r)>>1;
		add2(a,i*2+1,l,md);
		add2(a,i*2+2,md,r);
		val[i].fr=min(val[i*2+1],val[i*2+2]).fr+add[i];
		val[i].sc=min(val[i*2+1],val[i*2+2]).sc;
		
		pi mx;
		if(maxi[i*2+1].fr>=maxi[i*2+2].fr) mx=maxi[i*2+1];
		else mx=maxi[i*2+2];
		
		maxi[i]=mp(mx.fr+add[i],mx.sc);
	}
	pi query(){
		return val[0];
	}
	pi query2(){
		return maxi[0];
	}
};

segtree  seg;

char s[1000005];
int sum[1000005];
int n;
int main(){
	scanf("%s",s);
	n=strlen(s);

	if(s[n-1]=='L'){
		REP(i,n){
			if(s[i]=='R') s[i]='L';
			else s[i]='R';
		}
	}
	REP(i,n) sum[i+1]=sum[i]+(s[i]=='R'?1:-1);
	seg.init(n+1,sum);
	int res=0;
	int time=0;
	while(1){
		pi mini=seg.query();
		pi maxi=seg.query2();
		
		if(maxi.sc==n){
			++res;
			if(time==0) break;
		}
		if(mini.fr>=0) break;
		seg.add2(mini.sc,0,0,seg.n);
		++time;
	}
	cout<<res<<endl;
	return 0;
}