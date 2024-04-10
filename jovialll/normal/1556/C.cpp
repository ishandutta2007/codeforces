#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1005
#define mod 998244353
#define pb push_back
#define int long long
int T,n,m,i,j,k,x,y,a[N],ww,S[N],s[N][N],s_[N][N],pos[N],c[N],need,now,ans;
signed main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>c[i];
		if(i&1)S[i]=S[i-1]+c[i];
		else S[i]=S[i-1]-c[i];
	}
	for(i=1;i<=n;i+=2){
		now=need=0;
		for(j=i+1;j<=n;j+=2){
			s[i][j]=need;
			need=max(need,-now+c[j]);
			now-=c[j];now+=c[j+1];
		}
	}
	for(i=2;i<=n;i+=2){
		now=need=0;
		for(j=i-1;j>0;j-=2){
			s_[i][j]=need;
			need=max(need,-now+c[j]);
			now-=c[j];now+=c[j-1];
		}
	}
	for(i=1;i<=n;i+=2){
		for(j=i+1;j<=n;j+=2){
			if(s[i][j]>c[i]||s_[j][i]>c[j]){
				continue;
			}
			ww=S[j-1]-S[i]+s[i][j]-s_[j][i];
			if(ww>0){
				ans+=max(0ll,min(c[j]-s_[j][i]-ww,c[i]-s[i][j])+(j>i+1));
			}
			else{
				ans+=max(0ll,min(c[j]-s_[j][i],c[i]-s[i][j]+ww)+(j>i+1));
			}
		}
	}
	cout<<ans;
	return 0;
}