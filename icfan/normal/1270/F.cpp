#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
#define ll long long
#define Maxn 200000
#define Maxb 100
int n, nxt[Maxn+5], b[Maxn+5], c[Maxb*Maxn+5];
string s;
ll ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	n=s.size();
	nxt[n]=n;
	for(int i=n-1;i>=0;i--){
		nxt[i]=s[i]&1?i:nxt[i+1];
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+(s[i-1]&1);
	}
	for(int i=0;i<n;i++){
		for(int j=nxt[i],c=1;j<n&&i+c*Maxb<=n;j=nxt[j+1],c++){
			int l=max(j,i+c*Maxb-1),r=nxt[j+1]-1;
			ans+=max((r+c-(i+c-1)%c)/c-(l+c-1-(i+c-1)%c)/c,0);
		}
	}
	for(int i=1;i<Maxb;i++){
		for(int j=0;j<=n;j++){
			ans+=c[b[j]*i+n-j];
			c[b[j]*i+n-j]++;
		}
		for(int j=0;j<=n;j++){
			c[b[j]*i+n-j]--;
		}
	}
	cout<<ans<<endl;
	return 0;
}