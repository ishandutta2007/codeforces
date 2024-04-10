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
ll jc[250005],inv[250005];

vector<ll> v,v1[250005];

void dfs(int x,int fa){
	for(auto i:v1[x]){
		if(i!=fa){
			a[x]++;dfs(i,x);
		}
	}
}

vector<ll> work(int l,int r){
	if(l==r){
		return {1,a[l]};
	}
	return work(l,(l+r)/2)*work((l+r)/2+1,r);
}

int main(){
	jc[0]=inv[0]=1;
	for(i=1;i<=250000;i++){jc[i]=jc[i-1]*i%M;}
	inv[250000]=ksm(jc[250000],M-2);
	for(i=249999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	
	ios::sync_with_stdio(0);
	
	cin>>n;
	
	for(i=1;i<n;i++){
		cin>>j>>k;
		v1[j].push_back(k);
		v1[k].push_back(j);
	}
	dfs(1,0);
	v=work(1,n);
	
	ll res=0;
	for(i=n-1;i>=0;i--){
		if(i&1){
			res=su(res,M-v[i]*jc[n-i]%M);
		}
		else{
			res=su(res,v[i]*jc[n-i]%M);
		}
	}
	cout<<res;
}