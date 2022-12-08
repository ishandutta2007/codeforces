#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
inline int add(int a,int b){a+=b;return a>mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */
int n,k;

const int N = 2e5+5;

vector<int> d[N];
ll c[N];
ll dp[N],ans[N];

int main()
{
	for(int i=1;i<N;i++)for(int j=i;j<N;j+=i)d[j].push_back(i);
	cin >> n >> k;
	for(int s=n+1;s<n*2-1;++s){
		int l=s-n,r=n-1;
		for(size_t i=0;i<d[s].size();i++){
			int x=d[s][i];
			c[x]=(r/x)-(l/x);
		}
		for(size_t i=(int)d[s].size()-1;~i;i--){
			int x=d[s][i];
			for(size_t j=0;j<d[x].size();j++){
				int y=d[x][j];
				if(x!=y) c[y]-=c[x];
			}
		}
		for(size_t i=0;i<d[s].size();i++){
			int g=d[s][i];
			if(s-g>=n) ans[s-n]+=c[g];
		}
	}
	for(int m=2;m<=n;m++){
		dp[m] = (ll)m*(m-1)/2;
		ll b= (ll)sqrt(m);
		while(b*b<m)b++;
		for(int i=2;i<=b;i++){
			dp[m]-=dp[m/i];
		}
		for(int i=b;i;i--){
			ll z=m/i;
			if(z>b){
				dp[m]-=(z-b)*dp[i];
				b=z;
			}
		}
	}
	for(int g=1;g<n;g++){
		ans[g]+=dp[(n-1)/g+1];
	}
	int res=0;
	for(int i=1;i<n;i++){
		ans[i]+=mod;
		ans[i]%=mod;
		res=add(res, mul(ans[i], qpow(k,i)));
	}
	res=mul(res,qpow(qpow(k,n),mod-2));
	cout << res << endl;
	return 0;
}