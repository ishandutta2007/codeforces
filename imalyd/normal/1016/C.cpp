#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300005;
int n;
ll s123[2][N],s321[2][N],s111[2][N],a[2][N],ans;
ll right(int f,int v,int t){
	return s123[f][v]+(t-v)*s111[f][v];
}
ll left(int f,int v,int t){
	return s321[f][v]+t*s111[f][v];
}
int main(){
	cin>>n;
	for(int i=0;i<2;i++)for(int j=1;j<=n;j++)cin>>a[i][j];
	for(int i=0;i<2;i++){
		for(int j=n;~j;j--)s123[i][j]=s123[i][j+1]+j*a[i][j];
		for(int j=n;~j;j--)s321[i][j]=s321[i][j+1]+(n-j+1)*a[i][j];
		for(int j=n;~j;j--)s111[i][j]=s111[i][j+1]+a[i][j];
	}
	ll sum=0;
	for(int i=1;i<=n;i++){
		int f=1^(i&1),st=(i<<1)-2;
		ans=max(ans,sum+right(f,i,st)+left(f^1,i,st+n-i));
		sum+=st*a[f][i];
		f=i&1,st=(i<<1)-1;
		ans=max(ans,sum+right(f,i,st)+left(f^1,i+1,st+n-i));
		sum+=st*a[f][i];
	}cout<<ans;
    return 0;
}