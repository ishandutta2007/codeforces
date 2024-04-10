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
int n;
int val[405],ar[405];
int con[405][405],dp[405][405],dp2[405][405];//use all in the range

int res[405];
int main(){
	cin>>n;
	REP(i,n) cin>>val[i];
	REP(i,n) cin>>ar[i];
	
	for(int l=1;l<=n;++l){
		REP(i,n-l+1){
			int j=i+l,last=i+l-1;
			
			if(l==1){
				con[i][j]=0;
				dp[i][j]=dp2[i][j]=val[0];
				continue;
			}
			con[i][j]=-INF;
			for(int k=i+1;k<j;++k) if(abs(ar[i]-ar[k])==1 && (ar[k]-ar[i])*(lint)(ar[last]-ar[k])>=0){
				chmax(con[i][j],con[k][j]+dp2[i+1][k]);
			}
			dp[i][j]=-INF;
			for(int k=i;k<j;++k) if(ar[k]>=ar[i] && ar[k]>=ar[last]){
				int len=ar[k]*2-ar[i]-ar[last];
				if(len>=n || len<0) continue;
				chmax(dp[i][j],val[len]+con[i][k+1]+con[k][j]);
			}
			dp2[i][j]=dp[i][j];
			for(int k=i+1;k<j;++k){
				chmax(dp2[i][j],dp2[i][k]+dp2[k][j]);
			}
		}
	}

	res[0]=0;
	REP(i,n){
		res[i+1]=res[i];
		REP(j,i+1) chmax(res[i+1],res[j]+dp[j][i+1]);
	}
	cout<<res[n]<<endl;




			


	return 0;
}