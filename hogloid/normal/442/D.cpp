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


int n;
int par[1000005];

pair<pi,pi> mx[1000005];

inline int getcost(int v){
	return max(mx[v].fr.fr,mx[v].sc.fr+1);
}

void climb(int v){
	while(1){
		int p=par[v];
		if(p==-1) return;
		int cost=getcost(v);
		chmax(cost,1);
		if(mx[p].fr.fr<cost){
			if(mx[p].fr.sc==v) mx[p].fr=mp(cost,v);
			else{
				mx[p].sc=mx[p].fr;
				mx[p].fr=mp(cost,v);
			}
		}else if(mx[p].sc.fr<cost){
			if(mx[p].fr.sc==v) break;
			else mx[p].sc=mp(cost,v);
		}else break;
		v=p;
	}
}

int main(){
	cin>>n;
	par[0]=-1;
	mx[0]=mp(mp(0,0),mp(-1,-1));
	REPN(i,n+1,1){
		scanf("%d",&par[i]);--par[i];
		mx[i]=mp(mp(0,i),mp(-1,-1));
		climb(i);
		printf("%d%c",mx[0].fr.fr,i==n?'\n':' ');
	}

	return 0;
}