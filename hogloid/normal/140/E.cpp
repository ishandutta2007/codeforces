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
vector<lint> dp[1000005];
int n,m;
lint mod;
int L[1000005];

lint C[5005];
vector<int> fmod;

int cnt[50];

lint extgcd(lint a,lint b,lint& x,lint& y){
	if(b==0){
		x=1;y=0;
		return a;
	}
	lint d=extgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}

lint inv(lint a){
	lint x,y;
	extgcd(a,mod,x,y);
	return (mod+x%mod)%mod;
}

lint mpow(lint a,lint k){
	lint res=1;
	while(k){
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}

void apply(lint& ever,lint a,int add){
	REP(i,fmod.size()){
		while(a%fmod[i]==0){
			a/=fmod[i];
			cnt[i]+=add;
		}
	}
	if(add==1) ever=ever*a%mod;
	else ever=ever*inv(a)%mod;
}

int dp2[5005][5005];
int fact[1000005];
int main(){
	cin>>n>>m>>mod;
	fact[0]=1;
	REP(i,m+1) fact[i+1]=fact[i]*(lint)(i+1)%mod;

	dp2[0][0]=1;
	REP(i,5003) REP(j,5003) if(dp2[i][j]>0){
		dp2[i+1][j]=(dp2[i+1][j]+dp2[i][j]*(lint)max(0,j-1))%mod;
		dp2[i+1][j+1]=(dp2[i+1][j+1]+dp2[i][j])%mod;
	}

	int tmod=mod;
	for(int i=2;i*i<=tmod;++i) if(tmod%i==0){
		fmod.pb(i);
		while(tmod%i==0) tmod/=i;
	}
	if(tmod>1) fmod.pb(tmod);
	C[0]=1;
	lint ever=1;
	REP(i,min(5002,m)){
		apply(ever,m-i,1);
		apply(ever,i+1,-1);
		lint tmp=ever;
		REP(j,fmod.size()) tmp=(tmp*mpow(fmod[j],cnt[j]))%mod;
		
		C[i+1]=tmp;
	}


	REP(i,n) scanf("%d",&L[i]);
	
	dp[0].resize(1);
	REP(i,n) dp[i+1].resize(min(m+1,L[i]+1));
	
	dp[0][0]=1;
	REP(i,n) {
		lint total=0;
		REP(j,dp[i].size()) if(dp[i][j]>0){
			total+=dp[i][j]*C[j]%mod*fact[j];
			total%=mod;
		}

		REP(j,dp[i+1].size()){
			dp[i+1][j]=total;
			if(j<dp[i].size()){
				dp[i+1][j]+=mod-dp[i][j]*fact[j]%mod;
				if(dp[i+1][j]>=mod) dp[i+1][j]-=mod;
			}

			dp[i+1][j]=(dp[i+1][j]*dp2[L[i]][j])%mod;
		}
	}
	lint res=0;
	REP(i,dp[n].size()){
		res+=dp[n][i]*C[i]%mod*fact[i],res%=mod;
	}

	printf("%d\n",(int)res);			
	 

	return 0;
}