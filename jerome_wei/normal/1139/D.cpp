#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int qpow(ll a,ll b){a%=mod;int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
inline int inv(int x){
	return qpow(x,mod-2);
}
/*math*/
const int N=1e6+5;
int n;
int f[N];
vector<int> divisor[N];
const int maxn=1000000+10;
int mu[maxn],p[maxn],flag[maxn],cnt;
void mobius(int n){
  mu[1]=1;
  for(int i=2;i<=n;i++){
    if(!flag[i])p[++cnt]=i,mu[i]=-1;
    for(int j=1;j<=cnt && i*p[j]<=n;j++){
      flag[i*p[j]]=1;
      if(i%p[j]==0){mu[i*p[j]]=0;break;}
      mu[i*p[j]]=-mu[i];
    }
  }
}

int main()
{
	cin >> n;
	mobius(n);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			divisor[j].push_back(i);
		}
	}
	f[1]=1;
	int ans=inv(n);
	int _inv=inv(n);
	for(int i=2;i<=n;i++){
		int ttt=0;
		for(size_t p=0;p<divisor[i].size()-1;p++){
			int j=divisor[i][p];
			
			int t=i/j;
			int X=n/j;
			int numb=0;
			for(size_t ii=0;ii<divisor[t].size();ii++){
				int d=divisor[t][ii];
				numb+=mu[d]*(X/d);
			}
//			cout<<i<<" -> "<<j<<" "<<numb<<endl;
			ttt=add(ttt,mul(mul(_inv,numb),f[j]));
		}
		ttt=add(ttt,1);
		int POS=sub(1,mul(inv(n),n/i));
		f[i] = mul(inv(POS),ttt);
		ans = add(ans, mul(inv(n),f[i]));
	}
	cout<<ans<<endl;
}