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

lint readL(){
  lint res;
#ifdef ONLINE_JUDGE
  scanf("%I64d",&res);
#else
  scanf("%lld",&res);
#endif
  return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
  printf("%I64d",res);
#else
  printf("%lld",res);
#endif
}

//const int INF=5e8;
int n;
vector<pi> g[100005];

struct segtree{
	static const int MAX_N=270000;
	vector<lint> val[MAX_N];
	int n;
	void init(int n_,lint *a){
		n=1;
		while(n<n_) n<<=1;
		REP(i,n_) val[i+n-1].pb(a[i]);
		for(int i=n-2;i>=0;--i){
      val[i].resize(val[i*2+1].size()+val[i*2+2].size());
      merge(ALL(val[i*2+1]),ALL(val[i*2+2]),val[i].begin());
    }
	}
	int query(int a,int b,int i,int l,int r,lint k){
		if(a<=l && r<=b) return upper_bound(ALL(val[i]),k)-val[i].begin();;
		if(b<=l || r<=a) return 0;
		int md=(l+r)>>1;
		return query(a,b,i*2+1,l,md,k)+query(a,b,i*2+2,md,r,k);
	}
};
lint tmpar[100005],dist1[100005],dist2[100005];
void dfs(int v,int p,lint* ar,lint d){
  ar[v]=d;
  for(auto e:g[v]){
    if(e.fr==p) continue;
    dfs(e.fr,v,ar,d+e.sc);
  }
}

lint cost[100005];

int curidx;
bool judge(const pi& a){
  if(cost[a.fr]>cost[curidx] || (cost[a.fr]==cost[curidx] && a.fr>curidx)) return false;
  return true;
}

segtree seg;

int st[100005],fin[100005],cnt;

lint cost2[100005];
void prep(int v,int p){
  st[v]=cnt;
  ++cnt;
  for(auto e:g[v]){
    prep(e.fr,v);
  }
  fin[v]=cnt;
}

int rec(int v,lint l){
  int res=seg.query(st[v],fin[v],0,0,seg.n,cost[v]+l);
  for(auto e:g[v]){
    chmax(res,rec(e.fr,l));
  }
  return res;
}


int main(){
  cin>>n;
  REP(i,n-1){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;--b;
    g[a].pb(mp(b,c));
    g[b].pb(mp(a,c));
  }

  dfs(0,-1,tmpar,0);

  int p=max_element(tmpar,tmpar+n)-tmpar;
  dfs(p,-1,tmpar,0);
  int q=max_element(tmpar,tmpar+n)-tmpar;

  dfs(p,-1,dist1,0);
  dfs(q,-1,dist2,0);
  
  REP(i,n) cost[i]=max(dist1[i],dist2[i]);

  int r=-1;
  REP(i,n){
    int deg=g[i].size();
    curidx=i;
    g[i].erase(remove_if(ALL(g[i]),judge),g[i].end());
    if(deg==g[i].size()) r=i;

  }
  assert(r>=0);

  prep(r,-1);

  REP(i,n) cost2[st[i]]=cost[i];

  seg.init(n,cost2);

  int Q;cin>>Q;
  REP(hoge,Q){
    lint l;cin>>l;


    int res=rec(r,l);
    cout<<res<<endl;
  }
  return 0;
}