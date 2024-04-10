#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
using namespace std;
static const int INF =500000000; 
typedef long long int lint;
typedef pair<int,int> pi;
int n,k;
int s[100005];

struct segtree{
	int val[400005];
	int flip[400005];
	int n;
	void init(int n_){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n*2) val[i]=flip[i]=0;
	}
	void doit(int i,int l,int r){
		flip[i]^=1;
		val[i]=(r-l-val[i]);
	}
	void push(int i,int l,int r){
		if(flip[i]){
			int md=(l+r)>>1;
			flip[i]=0;
			doit(i*2+1,l,md);
			doit(i*2+2,md,r);
		}
	}

	void f(int a,int b,int i,int l,int r){
		if(a<=l && r<=b){
			doit(i,l,r);
			return;
		}
		if(b<=l || r<=a) return;
		int md=(l+r)>>1;
		push(i,l,r);
		f(a,b,i*2+1,l,md);
		f(a,b,i*2+2,md,r);
		val[i]=val[i*2+1]+val[i*2+2];
	}
	int query(int a,int b,int i,int l,int r){
		if(a<=l && r<=b) return val[i];
		if(b<=l || r<=a) return 0;
		int md=(l+r)>>1;
		push(i,l,r);
		return query(a,b,i*2+1,l,md)+query(a,b,i*2+2,md,r);
	}
};

segtree seg;
pi range[100005];
vector<int> edge[100005];

int main(){
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d",&s[i]);
	sort(s,s+n);
	REP(i,k){
		int a,b;scanf("%d%d",&a,&b);
		a=lower_bound(s,s+n,a)-s;
		b=upper_bound(s,s+n,b)-s;
		
		range[i]=mp(a,b);
		
		edge[a].pb(i);
		edge[b].pb(i);
	}
	seg.init(n);

	lint res=n*(lint)(n-1)*(n-2)/6;
	REP(i,n){
		REP(j,edge[i].size()){
			int id=edge[i][j];
			seg.f(range[id].fr,range[id].sc,0,0,seg.n);
		}

		int L=seg.query(0,i,0,0,seg.n),
			R=seg.query(i+1,n,0,0,seg.n);
		
		int L2=i-L,R2=n-1-i-R;
		
		int win=R2+L;
		res-=win*(lint)(win-1)/2;
	}
	cout<<res<<endl;

	return 0;
}