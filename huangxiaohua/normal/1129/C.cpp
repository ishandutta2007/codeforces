#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

#define M1 998244853
#define M2 666623333
#define N 19890604

int i,j,n,m,t,k,sb,cur;

ll f[3050][3050],res[3050],a[3050];
ll pw1[3050],pw2[3050],inv1[3050],inv2[3050];
ll hsh1[3050],hsh2[3050];

ll ksm1(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M1;}a=a*a%M1;p>>=1;}return res;}
ll ksm2(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M2;}a=a*a%M2;p>>=1;}return res;}

ll su(ll a,ll b){
	a+=b;return (a>=M)?a-M:a;
}

map<pair<ll,ll>,bool> mp;

pair<ll,ll> get(int l,int r){
	ll r1,r2;
	r1=(hsh1[r]-hsh1[l-1]+M1)*inv1[l-1]%M1;
	r2=(hsh2[r]-hsh2[l-1]+M2)*inv2[l-1]%M2;
	return {r1,r2};
}

int main() {
	pw1[0]=pw2[0]=inv1[0]=inv2[0]=1;
	for(i=1;i<=3005;i++){
		pw1[i]=pw1[i-1]*N%M1;
		pw2[i]=pw2[i-1]*N%M2;
	}
	inv1[3005]=ksm1(pw1[3005],M1-2);
	inv2[3005]=ksm2(pw2[3005],M2-2);
	for(i=3004;i>=1;i--){
		inv1[i]=inv1[i+1]*N%M1;
		inv2[i]=inv2[i+1]*N%M2;
	}
	
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		hsh1[i]=(hsh1[i-1]+pw1[i]*(a[i]+100))%M1;
		hsh2[i]=(hsh2[i-1]+pw2[i]*(a[i]+100))%M2;
	}
	
	for(i=1;i<=n;i++){
		f[i][i-1]=1;
		for(j=i;j<=n;j++){
			f[i][j]=su(f[i][j-1],f[i][j]);
			k=j-i+1;
			if(k>=2)f[i][j]=su(f[i][j-2],f[i][j]);
			if(k>=3)f[i][j]=su(f[i][j-3],f[i][j]);
			if(k>=4){
				k=a[j-3]+a[j-2]*2+a[j-1]*4+a[j]*8;
				if(k!=12&&k!=10&&k!=7&&k!=15){
					f[i][j]=su(f[i][j-4],f[i][j]);
				}
			}
		}
	}
	
	for(i=1;i<=n;i++){
		mp.clear();
		for(j=i;j<=n;j++){
			auto it=get(j-i+1,j);
			if(!mp.count(it)){res[j]=su(res[j],f[j-i+1][j]);}
			mp[it]=1;
		}
	}
	
	for(i=1;i<=n;i++){
		res[i]=su(res[i],res[i-1]);
		cout<<res[i]<<'\n';
	}
}