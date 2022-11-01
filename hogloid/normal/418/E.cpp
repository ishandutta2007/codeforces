#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;
using namespace __gnu_pbds;

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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;


namespace std{
	template<class S,class T>
	ostream &operator <<(ostream& out,const pair<S,T>& a){
		out<<'('<<a.fr<<','<<a.sc<<')';
		return out;
	}
}
//const int INF=5e8;
static const int MAXN=100005,B=1500;
struct BIT{
	int val[MAXN*2+2];
	int n,all=0;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n+1) val[i]=0;
	}
	void add(int k,int a){
		++k;
		all+=a;
		while(k<=n){
			val[k]+=a;
			k+=k&-k;
		}
	}
	int query(int k){	//[k...)
		int res=0;
		while(k>0){
			res+=val[k];
			k-=k&-k;
		}
		return all-res;
	}
	BIT operator=(const BIT& a){
		n=a.n;
		REP(i,n+1) val[i]=a.val[i];
		return *this;
	}
};

BIT bit[MAXN/B+5];


int n;
int ar[100005];
int m;
typedef unordered_map<int,int> map_t;
map_t cnt[MAXN/B+5];
int count(int idx,int key){
	if(idx<0) return 0;
	if(cnt[idx].count(key)) return cnt[idx][key];
	return 0;
}

void fix(int k,int val,int add){
	for(int i=k/B;i*B<n;++i){
		bit[i].add(cnt[i][val],-1);
		cnt[i][val]+=add;
		bit[i].add(cnt[i][val],1);
	}
}

int one(int k){
	int sum=count(k/B-1,ar[k]);
	debug(ar,ar+n);
	for(int i=k/B*B;i<=k;++i) if(ar[i]==ar[k]) ++sum;
	dump(sum);
	return sum;
}

int app[200005];
int two(int k){
	int num=one(k);
	dump(num);
	int b=k/B-1;
	int sum=(b>=0?bit[b].query(num):0);
	dump(b);
	dump(sum);

	for(int i=k/B*B;i<=k;++i){
		++app[ar[i]];
		if(count(b,ar[i])+app[ar[i]]==num) ++sum;
	}
	for(int i=k/B*B;i<=k;++i) --app[ar[i]];
	return sum;
}

int rev[200005];
map<int,int> conver;
int conv(int a){
	if(conver.count(a)) return conver[a];
	int k=conver.size();
	conver[a]=k;
	rev[k]=a;

	return k;
}


int main(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",&ar[i]);
	REP(i,n/B+1) bit[i].init(n+1);
	REP(i,n){
		ar[i]=conv(ar[i]);
		fix(i,ar[i],1);
	}

	scanf("%d",&m);
	REP(hoge,m){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		
		if(a==1){
			--c;
			fix(c,ar[c],-1);
			ar[c]=conv(b);
			fix(c,ar[c],1);
		}else{
			--b;--c;
			swap(b,c);
			int res;
			if(c==0) res=rev[ar[b]];
			else if(c&1) res=one(b);
			else res=two(b);

			printf("%d\n",res);
		}
	}


	return 0;
}