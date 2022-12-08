#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll k;
int h[200010];
int ans=0;
ll tot=0;
ll numb=0;
int mx=0;
int mn=19260817;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		h[x]++;
		mx=max(mx,x);
		mn=min(mn,x);
	}
	for(int i=mx;i>mn;i--){
		numb+=h[i];
		if(numb+tot>k)ans++,tot=numb;
		else tot+=numb;
	}
	ans++;
	if(mx==mn)ans=0;
	printf("%d\n",ans);
}