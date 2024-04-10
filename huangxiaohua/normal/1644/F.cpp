#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353
const int G = 3;
const int Gi = 332748118;

ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
int r[1000500], lim;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

void ntt (vector <ll> &A, int type) {
	for (int i = 0;i <= lim - 1;++i) {
		if (i < r[i]) swap(A[i], A[r[i]]);
	}
	for (int mid = 1;mid <= lim - 1;mid <<= 1) {
		ll Wn = ksm(type == 1 ? G : Gi, (M - 1) / (mid << 1));
		for (int j = 0;j <= lim - 1;j += (mid << 1)) {
			ll w = 1;
			for (int k = 0;k <= mid - 1;++k, w = (w * Wn) % M) {
				int x = A[j + k];
				int y = w * A[j + mid + k] % M;
				A[j + k] = su(x,y);
				A[j + mid + k] = su(x,M-y);
			}
		}
	}
	if (type == -1) {
		ll tmp = ksm(lim,M-2);
		for (int i = 0;i <= lim - 1;++i) {
			A[i] = A[i] * tmp % M;
		}
	}
}
vector <ll> operator * (vector <ll> A, vector <ll> B) {
	int len = A.size() + B.size() - 1;
	lim = 1;
	while (lim <= len) lim <<= 1;
	for (int i = 0;i <= lim - 1;++i) {
		r[i] = (r[i >> 1] >> 1) | ((i & 1) * (lim >> 1));
	}
	A.resize(lim);
	B.resize(lim);
	ntt(A, 1);
	ntt(B, 1);
	for (int i = 0;i <= lim - 1;++i) {
		A[i] = A[i] * B[i] % M;
	}
	ntt(A, -1);
	A.resize(len);
	return A;
}

int i,j,k,n,m,t,a[250005];
ll jc[250005],inv[250005],f[200500],sb[200500];
vector<ll> v;

ll work(int n){
	int i,j,k;
	if(!sb[n])return sb[n];
	sb[n]=0;
	vector<ll> a(n+1),b(n+1),res;
	for(i=0;i<=n;i++){
		a[i]=(i&1)?M-inv[i]:inv[i];
		b[i]=1ll*ksm(i,n)*inv[i]%M;
	}
	res=a*b;
	for(i=1;i<=min(n,m);i++){
		sb[n]=su(sb[n],res[i]);
	}
	return sb[n];
}

int main(){
	memset(sb,-1,sizeof(sb));
	jc[0]=inv[0]=1;
	for(i=1;i<=200050;i++){jc[i]=jc[i-1]*i%M;}
	inv[200050]=ksm(jc[200050],M-2);
	for(i=199999+50;i>=1;i--)inv[i]=inv[i+1]*(i+1)%M;
	cin>>n>>m;
	if(m==1){cout<<1;return 0;}
	for(i=n;i>=1;i--){
		f[i]=work((n+i-1)/i);
		for(j=i+i;j<=n;j+=i)f[i]=su(f[i],M-f[j]);
		if(n%i)f[i]=su(f[i],M-f[n]);
	}
	cout<<f[1];
}