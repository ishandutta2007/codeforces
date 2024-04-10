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
const int INF=5e8;
int n,m;
int dp1[2][2005],dp2[2][2005];

int pud[100005],ispud[200005],pudsum[200005];
int mark[200005],marksum[200005];
int con[200005];
int MX=200003;
int main(){
	cin>>n>>m;

	int st=MX;
	REP(i,n){
		int a;scanf("%d",&a);
		ispud[a]=1;
		pud[i]=a;
		chmin(st,a);
	}


	sort(pud,pud+n);
	REP(i,m){
		int a;scanf("%d",&a);
		mark[a]=1;
	}

	REP(i,MX){
		pudsum[i+1]=pudsum[i]+ispud[i];
		marksum[i+1]=mark[i]+marksum[i];
	}
	REP(i,MX) if(ispud[i] && ispud[i+1]) con[i]=1;
	REP(k,2) REP(j,2005) dp1[k][j]=dp2[k][j]=INF;
	int cur=0,nxt=1;
	dp1[cur][0]=0;

	int ans=0;
	for(int i=st;i<MX;++i){
		REP(j,m+1) if(dp1[cur][j]<=n){
			chmax(ans,j);
			chmin(dp1[nxt][j],dp1[cur][j]);
		
			if(ispud[i]){
				int sum=pudsum[i+1]-dp1[cur][j];
				if(sum<=0) continue;
				int nmark=marksum[i+1]-marksum[i+1-sum];
				chmin(dp2[cur][j+nmark],pudsum[i+1]);
			}
		}
		REP(j,m+1) if(dp2[cur][j]<=n){
			chmax(ans,j);
			chmin(dp2[nxt][j+mark[i+1]],dp2[cur][j]+1);
			if(!con[pud[dp2[cur][j]-1]]) chmin(dp1[nxt][j],dp2[cur][j]);
		}

		swap(cur,nxt);
		REP(j,m+1) dp1[nxt][j]=dp2[nxt][j]=INF;
	}


	cout<<ans<<endl;





	return 0;
}