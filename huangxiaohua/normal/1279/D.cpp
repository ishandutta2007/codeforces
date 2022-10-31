#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353

int i,j,k,n,t,m,a[1005000];
ll res,inv;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

vector<int> v[1005000];

int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>m;
		for(j=1;j<=m;j++){
			cin>>k;v[i].push_back(k);
			a[k]++;
		}
	}
	for(i=1;i<=n;i++){
		k=v[i].size();
		inv=ksm(n,M-2)*ksm(k,M-2)%M*ksm(n,M-2)%M;
		for(auto j:v[i]){
			res=su(res,inv*a[j]%M);
		}
	}
	cout<<res;
}