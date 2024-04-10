
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



//const int INF=5e8;
struct segtree{
	pi maxi[400005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
	}
	void set(int k,pi a){
		k+=n-1;
		chmax(maxi[k],a);
		while(k>0){
			k=(k-1)/2;
			chmax(maxi[k],a);
		}
	}
	pi query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return maxi[i];
		if(b<=l || r<=a) return mp(0,-1);
		int md=(l+r)>>1;
		return max(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
	}
};
segtree seg;

lint zip[100005];
int n;
lint d;
lint h[100005];

int back[100005];
int main(){
	cin>>n>>d;
	REP(i,n){
		cin>>h[i];
		zip[i]=h[i];
	}
	sort(zip,zip+n);
	int m=unique(zip,zip+n)-zip;

	REP(i,n){
		h[i]=lower_bound(zip,zip+m,h[i])-zip;
	}
	seg.init(m);
	
	int ans=0,who;	
	memset(back,-1,sizeof(back));
	REP(i,n){
		int lb=lower_bound(zip,zip+m,zip[h[i]]+d)-zip;
		int ub=upper_bound(zip,zip+m,zip[h[i]]-d)-zip;

		pi res=max(seg.query(0,ub,0,0,seg.n),seg.query(lb,seg.n,0,0,seg.n));
		
		if(res.fr==0) res.sc=-1;
		if(ans<res.fr+1){
			ans=res.fr+1;
			who=i;
		}
		seg.set(h[i],mp(res.fr+1,i));
		back[i]=res.sc;
	}

	cout<<ans<<endl;
	vector<int> res;
	res.pb(who);
	while(back[who]!=-1){
		who=back[who];
		res.pb(who);
	}
	reverse(ALL(res));
	REP(i,res.size()) printf("%d%c",res[i]+1,i==ans-1?'\n':' ');

	return 0;
}