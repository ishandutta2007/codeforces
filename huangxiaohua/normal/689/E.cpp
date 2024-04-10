#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
int i,j,k,n,t,a[200500],cur,m,x,y,st;
ll jc[200500],inv[200500],res;
unordered_map<int,int> mp;
set<int> s;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

ll c(int n,int m){
	if(m>n){return 0;}
	return jc[n]*inv[m]%M*inv[n-m]%M;
}
 
int main(){
	jc[0]=inv[0]=1;for(i=1;i<=200000;i++){jc[i]=jc[i-1]*i%M;}
	inv[200000]=ksm(jc[200000],M-2);for(i=199999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		s.insert(x);s.insert(y+1);
		mp[x]++;mp[y+1]--;
	}
	for(auto i:s){
		a[cur]+=i-st;
		st=i;cur+=mp[i];
	}
	for(i=m;i<=n;i++){
		res+=c(i,m)*a[i]%M;
	}
	printf("%lld",res%M);
}