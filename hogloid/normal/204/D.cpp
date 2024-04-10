#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
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
int n,k;
char s[1000005];
lint butB[1000005],butW[1000005];
lint leftt[1000005],rightt[1000005];
int wsum[1000005],bsum[1000005];
const lint mod=1000000007;
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	REP(i,n){
		wsum[i+1]=wsum[i];
		bsum[i+1]=bsum[i];
		if(s[i]=='W') ++wsum[i+1];
		else if(s[i]=='B') ++bsum[i+1];
	}
	butB[0]=1;
	REP(i,n){
		if(i+1-k>=0 && wsum[i+1]-wsum[i+1-k]==0 && (i-k<0 || s[i-k]!='B')) leftt[i+1]=butB[max(0,i-k)];
		butB[i+1]=butB[i];
		if(s[i]=='X') butB[i+1]*=2;
		butB[i+1]-=leftt[i+1];
		butB[i+1]=(butB[i+1]%mod+mod)%mod;
	}
	butW[n]=1;
	for(int i=n-1;i>=0;--i){
		if(i+k<=n && bsum[i+k]-bsum[i]==0 && (i+k==n || s[i+k]!='W')) rightt[i]=butW[min(i+k+1,n)];
		butW[i]=butW[i+1];
		if(s[i]=='X') butW[i]*=2;
		butW[i]-=rightt[i];
		butW[i]=(butW[i]%mod+mod)%mod;
	}

	lint pow2=1,res=0;
	for(int i=n-1;i>=0;--i){
		if(s[i]=='X') pow2*=2,pow2%=mod;
		lint form,lat;
		lat=(pow2+mod-butW[i])%mod;
		form=leftt[i];
		res+=form*lat%mod;
		res%=mod;
	}
	cout<<res<<endl;
	return 0;
}