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

stack<int> stk;
int n,m;
char s[1000005];
int sum[1000005];

int nxt[20][1000005];
int main(){
	scanf("%s",s);
	n=strlen(s);
	REP(i,n) sum[i+1]=sum[i]+(s[i]=='('?1:-1);

	stk.push(0);
	REPN(i,n+1,1){
		if(sum[stk.top()]<=sum[i]) stk.push(i);
		else{
			while(!stk.empty() && sum[stk.top()]>sum[i]){
				int p=stk.top();stk.pop();
				nxt[0][p]=i;
			}
			stk.push(i);
		}
	}
	while(!stk.empty()){
		nxt[0][stk.top()]=n+1;
		stk.pop();
	}

	REP(i,19) REP(j,n+1){
		if(nxt[i][j]==n+1) nxt[i+1][j]=n+1;
		else nxt[i+1][j]=nxt[i][nxt[i][j]];
	}


	cin>>m;

	REP(hoge,m){
		int l,r;scanf("%d%d",&l,&r);--l;
		int res=0;
		for(int i=19;i>=0;--i){
			if(nxt[i][l]<=r){
				res+=nxt[i][l]-l-(1<<i);
				l=nxt[i][l];
			}
		}
		res+=r-l-(sum[r]-sum[l]);
		printf("%d\n",res);
	}



	return 0;
}