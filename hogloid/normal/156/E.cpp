#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n;
lint a[10005];
int prime[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,87,89,97};
int mod[5]=   {2*3*5*7*11*13*17*19*23,29*31*37*41*43,47*53*59*61*67,71*73*79*83,87*89*97};
int begin[6]= {0,9,14,19,23,26};



vector<lint> dp[17][5];
int dig[20];
int mlen[20];
lint rec(int d,int m){
	int x=0;
	REP(i,mlen[d]) x=x*(d+1)+dig[i];
	lint& res=dp[d][m][x];
	if(res!=-1) return res;
	res=1;
	REP(i,mlen[d]) if(dig[i]==d){
		REP(j,d){
			dig[i]=j;
			res=res*rec(d,m)%mod[m];
		}
		dig[i]=d;
		return res;
	}
	int y=0;
	REP(i,mlen[d]) y=y*d+dig[i];
	if(y<n) res=a[y]%mod[m];
	return res;
}

int main(){
	cin>>n;
	REP(i,n) cin>>a[i];
	int m;
	cin>>m;
	
	for(int i=2;i<=16;++i){
		int maxlen=0,sum=1;
		while(sum<n){
			sum*=i;
			++maxlen;
		}
		mlen[i]=maxlen;
		int t=1;
		REP(j,maxlen) t*=i+1;
		REP(j,5) dp[i][j].resize(t,-1);
	}


	while(m--){
		int d;
		lint c;
		string s;
		cin>>d>>s>>c;
		
		int fail=0;
		memset(dig,0,sizeof(dig));
		REP(i,s.size()){
			int p=mlen[d]-(s.size()-i);
			if(p<0 && s[i]!='?' && s[i]!='0') fail=1;
			else if(p>=0){
				if(s[i]=='?') dig[p]=d;
				else dig[p]=(s[i]>='A'?s[i]-'A'+10:s[i]-'0');
			}
		}
		if(fail) ;

		int suc=0;
		REP(i,5){
			lint prod=0;
			if(!fail) prod=rec(d,i);

			prod=(prod+c)%mod[i];
			
			for(int j=begin[i];j<begin[i+1];++j) if(prod%prime[j]==0){
				suc=1;
				printf("%d\n",prime[j]);
				goto exi;
			}
		}
exi:;
		if(!suc) puts("-1");
	}

	return 0;
}