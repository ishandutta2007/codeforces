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
	int e[200005],nxt[200005],begin[100005],cnt;
	int n;
	lint totdist[100005];
	
	int size[100005];
	lint sum_dist;

	void getdist(int v,int p){
		size[v]=1;
		for(int it=begin[v];~it;it=nxt[it]){
			int to=e[it];
			if(to==p) continue;
			getdist(to,v);
			size[v]+=size[to];
			totdist[v]+=totdist[to];
		}
		totdist[v]+=size[v]-1;
	}

	void getdist2(int v,int p,lint sum){
		for(int it=begin[v];~it;it=nxt[it]){
			int to=e[it];
			if(to==p) continue;
			getdist2(to,v,sum+totdist[v]-(totdist[to]+size[to])+n-size[to]);
		}
		totdist[v]+=sum;
	}

	lint maxdist;
	void init(int n_){
		n=n_;
		memset(begin,-1,sizeof(begin));
		cnt=0;
		REP(i,n-1){
			int a,b;scanf("%d%d",&a,&b);--a;--b;

			e[cnt]=b;nxt[cnt]=begin[a];begin[a]=cnt++;
			e[cnt]=a;nxt[cnt]=begin[b];begin[b]=cnt++;
		}

		maxdist=sum_dist=0;
		getdist(0,-1);
		getdist2(0,-1,0);
		REP(i,n){
			chmax(maxdist,totdist[i]);
			sum_dist+=totdist[i];
		}
		debug(totdist,totdist+n);
		sum_dist/=2;
	}

	lint dis1,dis3;
	int n1,n3;
	int cut[100005];

	
	lint res;
	pll dfs(int v,int p,int d){
		pll nxtt=mp(totdist[v]*n1+d*(lint)n1*n3,totdist[v]*n3+d*(lint)n1*n3);
		
		chmax(res,nxtt.fr+nxtt.sc-2LL*d*n1*n3);
		for(int it=begin[v];~it;it=nxt[it]){
			int to=e[it];
			if(to==p) continue;

			pll nxt2=dfs(to,v,d+1);
			chmax(res,nxtt.fr+nxt2.sc-2LL*d*(lint)n1*n3);
			chmax(res,nxtt.sc+nxt2.fr-2LL*d*(lint)n1*n3);

			chmax(nxtt.fr,nxt2.fr);
			chmax(nxtt.sc,nxt2.sc);

		}
		return nxtt;
	}


		
	lint query(lint A,lint B,int n1_,int n3_){
		dump(n);
		dis1=A;dis3=B;
		n1=n1_;n3=n3_;
		CLR(cut);
		res=0;
		dfs(0,-1,0);
		res+=(dis1+dis3)*n;
		res+=n1*dis3;
		res+=n3*dis1;
		res+=2ll*n1*n3;
		res+=1ll*n1*n;
		res+=1ll*n*n3;

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
	do{
		if(perm[0]>perm[2]){
			chmax(res,
				T[perm[1]].query(T[perm[0]].maxdist,T[perm[2]].maxdist,n[perm[0]],n[perm[2]]));
		}
	}while(next_permutation(perm,perm+3));
	res+=base;

	cout<<res<<endl;


	return 0;
}