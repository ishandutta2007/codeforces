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
//

int n,m,n2;
int g[2005][2005];
int order[2005],low[2005],cnt;
stack<int> cur;
int group[2005],gcnt;
int dfs(int v,int p){
	order[v]=cnt++;
	low[v]=order[v];
	cur.push(v);
	REP(i,n) if(g[v][i]){
		int to=i;
		if(to==p) continue;
		if(order[to]!=-1){
			low[v]=min(low[v],order[to]);
		}else{
			low[v]=min(low[v],dfs(to,v));
		}
	}
	if(low[v]<order[v]) return low[v];
	while(!cur.empty() && cur.top()!=v){
		group[cur.top()]=gcnt;
		cur.pop();
	}
	group[cur.top()]=gcnt;
	cur.pop();
	++gcnt;
	return low[v];
}


vector<int> g2[2005];
int size[2005];

int subsize[2005];

void prep(int v,int p){
	subsize[v]=size[v];
	for(auto to:g2[v]){
		if(to==p) continue;
		prep(to,v);
		subsize[v]+=subsize[to];
	}
}

bool tmp[4005];
int dfs2(int v,int p){
	int res=0;
	for(auto to:g2[v]){
		if(to==p) continue;
		res+=dfs2(to,v);
	}
	if(p!=-1){
		res+=size[v]*(subsize[v]-size[v]);
	}else{
		res+=size[v]*(subsize[v]-size[v]);

		int sub=subsize[v]-size[v];
		CLR(tmp);
		tmp[0]=true;
		for(auto to:g2[v]){
			for(int j=n2;j>=0;--j) if(tmp[j]) tmp[j+subsize[to]]=true;
		}

		int maxi=-1;
		REP(i,n2+1) if(tmp[i]) chmax(maxi,i*(sub-i));

		res+=maxi;
	}

	return res;
}


int main(){
	cin>>n>>m;
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a][b]=g[b][a]=1;
	}

	memset(order,-1,sizeof(order));
	dfs(0,-1);


	n2=n;
	prl;
	
	debug(group,group+n);
	REP(i,n){
		size[group[i]]++;
		REP(j,n) if(g[i][j] && group[i]!=group[j] && i>j){
			g2[group[i]].pb(group[j]);
			g2[group[j]].pb(group[i]);
		}
	}
	prl;

	n=gcnt;
	REP(i,n) debug(ALL(g2[i]));

	
	int res=0;
	REP(i,n){
		prep(i,-1);
		
		bool fail=0;
		for(auto to:g2[i]) if(subsize[to]*2>n2){
			fail=1;
		}
		if(!fail){
			int tmp=dfs2(i,-1);
			chmax(res,tmp);
		}
	}
	REP(i,n) res+=size[i]*size[i];

	cout<<res<<endl;






	return 0;
}