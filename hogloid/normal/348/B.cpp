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
int ar[100005];
vector<int> g[100005];
const lint INF=1e18;
lint L=1;

lint gcd(lint a,lint b){
	if(a>b) swap(a,b);
	while(a){
		b%=a;
		swap(a,b);
	}
	return b;
}

lint sum;
lint lcm(lint a,lint b){
	lint g=gcd(a,b);
	if(g==0) return INF;

	double res=a/(double)g*b;

	if(res>=1.1e13){
		cout<<sum<<endl;
		exit(0);
	}
	return a/g*b;
}

lint mul[100005];
void rec(int v,int p,lint cur){
	int chil=g[v].size();
	if(p!=-1) --chil;
	L=lcm(L,cur);

	mul[v]=cur;
	for(auto to:g[v]){
		if(to==p) continue;

		double mul2=cur*(double)chil;
		if(mul2>=1.1e13){
			cout<<sum<<endl;
			exit(0);
		}
		rec(to,v,cur*chil);
	}
}

int main(){
	cin>>n;
	sum=0;
	REP(i,n){
		scanf("%d",&ar[i]);
		sum+=ar[i];
	}

	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}

	rec(0,-1,1);

	{
		lint maxi=INF;
		REPN(i,n,1) if(g[i].size()==1){
			lint frac=L/mul[i];
			chmin(maxi,ar[i]/frac);
		}
		lint sum=accumulate(ar,ar+n,0ll);
		REPN(i,n,1) if(g[i].size()==1){
			lint frac=L/mul[i];
			sum-=frac*maxi;
		}
		cout<<sum<<endl;
	}
	return 0;
}