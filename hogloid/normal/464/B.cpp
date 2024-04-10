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
typedef pair<lint,lint> pi;

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
typedef vector<lint> P;
P ps[10];
P res[10];

P adj[4],other[4];
int n=8;


P calc(P a,P b,P c){
	P res(3);
	REP(i,3) res[i]=a[i]+b[i]-c[i];
	return res;
}

bool same(P a,P b){
	sort(ALL(a));sort(ALL(b));
	return a==b;
}

void print(){
	puts("YES");
	int used[8]={0};
	REP(i,8) {
		REP(j,8) if(!used[j] && same(res[j],ps[i])){
			printf("%d %d %d\n",(int)res[j][0],(int)res[j][1],(int)res[j][2]);
			used[j]=1;
			break;
		}
	}
	exit(0);
}

void check(){
	P want[4];
	want[0]=calc(adj[1],adj[2],adj[0]);
	want[1]=calc(adj[2],adj[3],adj[0]);
	want[2]=calc(adj[1],adj[3],adj[0]);
	want[3]=calc(want[0],adj[3],adj[0]);

	int perm[4]={0,1,2,3};

	do{
		int fail=0;
		REP(i,4) if(!same(other[perm[i]],want[i])) fail=1;

		if(!fail){
			REP(i,4) res[i]=adj[i];
			REP(i,4) res[i+4]=want[i];
			print();
		}
	}while(next_permutation(perm,perm+4));
}

P subt(P a,P b){
	P res(3);
	REP(i,3) res[i]=a[i]-b[i];
	return res;
}
lint dot(P a,P b){
	lint res=0;
	REP(i,3) res+=a[i]*b[i];
	return res;
}
lint len(P a){
	lint res=0;
	REP(i,3) res+=a[i]*a[i];
	return res;
}


void dfs(int ind){
	if(ind==4){
		P a=subt(adj[1],adj[0]),b=subt(adj[2],adj[0]),c=subt(adj[3],adj[0]);
		if(dot(a,b) || dot(b,c) || dot(c,a) || 
				len(a)!=len(b) || len(b)!=len(c) || len(c)!=len(a) || len(a)==0);
		else check();
		return;
	}
	sort(ALL(adj[ind]));
	do{
		dfs(ind+1);
	}while(next_permutation(ALL(adj[ind])));
}

int main(){
	REP(i,n){
		ps[i].resize(3);
		REP(j,3) cin>>ps[i][j];
	}

	int perm[7]={0};
	REP(i,3) perm[6-i]=1;

	do{
		int cnt=0;
		adj[cnt++]=ps[0];
		REP(i,7) if(perm[i]) adj[cnt++]=ps[i+1];
		

		cnt=0;
		REP(i,7) if(!perm[i]) other[cnt++]=ps[i+1];

		dfs(0);
	}while(next_permutation(perm,perm+7));
	
	puts("NO");

	return 0;
}