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

const int INF=5e8;
typedef pair<lint,lint> pll;
struct Tree{
	vector<int> g[100005];
	int n;

	map<pi,lint> totdist2;
	map<pi,int> size;
	lint totdist[100005];

	lint sum_dist;

	lint getdist(int v,int p){
		if(totdist2.count(mp(v,p))) return totdist2[mp(v,p)];
		lint& res=totdist2[mp(v,p)];
		int& s=size[mp(v,p)];
		s=1;
		for(auto to:g[v]){
			if(to==p) continue;
			res+=getdist(to,v);
			s+=size[mp(to,v)];
		}
		res+=s-1;
		return res;
	}

	lint maxdist;
	void init(int n_){
		n=n_;
		REP(i,n-1){
			int a,b;scanf("%d%d",&a,&b);--a;--b;
			g[a].pb(b);
			g[b].pb(a);
		}

		maxdist=sum_dist=0;
		REP(i,n){
			totdist[i]=getdist(i,-1);
			chmax(maxdist,totdist[i]);
			sum_dist+=totdist[i];
		}
		sum_dist/=2;
	}

	lint dis1,dis3;
	int n1,n3;
	int cut[100005];
	int bal,whole,root;
	
	int subs[100005];
	void getsize(int v,int p){
		subs[v]=1;
		for(auto to:g[v]){
			if(cut[to] || to==p) continue;
			getsize(to,v);
			subs[v]+=subs[to];
		}
	}
	void getroot(int v,int p){
		int mx=whole-subs[v];
		for(auto to:g[v]){
			if(cut[to] || to==p) continue;
			getroot(to,v);
			chmax(mx,subs[to]);
		}
		if(mx<bal){
			bal=mx;
			root=v;
		}
	}

	pair<lint,lint> dfs2(int v,int p,int d){
		pll res;
		res.fr=totdist[v]*n1+d*(lint)n1*n3;
		res.sc=totdist[v]*n3+d*(lint)n1*n3;

		for(auto to:g[v]){
			if(to==p || cut[to]) continue;
			pll nxt=dfs2(to,v,d+1);
			chmax(res.fr,nxt.fr);
			chmax(res.sc,nxt.sc);
		}
		return res;
	}

	lint dfs(lint v){
		bal=INF;
		getsize(v,-1);
		whole=subs[v];
		if(whole==1) return 0;
		getroot(v,-1);
		

		v=root;
		
		lint ever1=totdist[v]*n1,
			 ever2=totdist[v]*n3;

		lint res=-1;
		for(auto to:g[v]){
			if(cut[to]) continue;
			pll nxt=dfs2(to,v,1);
			chmax(res,ever1+nxt.sc);
			chmax(res,ever2+nxt.fr);

			chmax(ever1,nxt.fr);
			chmax(ever2,nxt.sc);
		}
		
		cut[v]=1;
		for(auto to:g[v]){
			if(cut[to]) continue;
			chmax(res,dfs(to));
		}

		return res;
	}

	

		
	lint query(lint A,lint B,int n1_,int n3_){
		dis1=A;dis3=B;
		n1=n1_;n3=n3_;
		prl;
		CLR(cut);
		dump(n);
		lint res=dfs(0);
		dump(res);dump(dis1);dump(dis3);dump(n1);dump(n3);
		res+=(dis1+dis3)*n;
		res+=n1*dis3;
		res+=n3*dis1;
		res+=2ll*n1*n3;
		res+=1ll*n1*n;
		res+=1ll*n*n3;
		dump(res);

		return res;
	}
};

Tree T[3];
int n[3];

int main(){
	cin>>n[0]>>n[1]>>n[2];
	REP(i,3){
		T[i].init(n[i]);
	}
	int perm[3]={0,1,2};

	lint res=0,base=T[0].sum_dist+T[1].sum_dist+T[2].sum_dist;
	prl;
	do{
		if(perm[0]>perm[2]){
			chmax(res,
				T[perm[1]].query(T[perm[0]].maxdist,T[perm[2]].maxdist,n[perm[0]],n[perm[2]]));
		}
	}while(next_permutation(perm,perm+3));
	dump(base);
	res+=base;

	cout<<res<<endl;


	return 0;
}