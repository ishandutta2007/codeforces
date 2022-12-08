#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+10,K = 60;
ll a[N],b[K][N];
int f[K][N];
int n;
inline int getsum(int k,ll x){
	ll w=1ll<<(k-1);
	if(x<w)return upper_bound(b[k],b[k]+n,x+w)-upper_bound(b[k],b[k]+n,x);
	else return (upper_bound(b[k],b[k]+n,x-w)-b[k])+(b[k]+n-upper_bound(b[k],b[k]+n,x));
}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	for(int k=1;k<K;++k){
		long long U = (1ll<<k)-1;
		for(int i=0;i<n;i++){
			b[k][i]=a[i]&U;
		}
		sort(b[k],b[k]+n);
	}
	for(int k=0;k<K;k++)for(int i=0;i<=n;i++)f[k][i]=0x3f3f3f3f;
	f[0][n]=0;
	for(int k=1;k<K;k++){
		for(int i=0;i<=n;i++){
			if(f[k-1][i]==0x3f3f3f3f)continue;
			if(i==0&&b[k-1][i]==0)continue;
			for(ll bit=0;bit<2;bit++){
				ll x=(i==0?0:b[k-1][i-1])+(bit<<(k-1));
				int pos = upper_bound(b[k],b[k]+n,x)-b[k];
				f[k][pos] = min(f[k][pos], f[k-1][i] + getsum(k,x));
			}
		}
	}
	cout << f[K-1][n] << endl;
}