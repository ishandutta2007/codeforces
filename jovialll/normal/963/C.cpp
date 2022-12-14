#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
#define M 1000000007
#define MM 1000000009
vector<ll>a[N];
map<ll,int>p1,p2,p3;
ll w[N],ans,h[N],c[N],c1,c2;
inline ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int cnt,tot;
//void cal(int x){
//	f1=x;f2=a[1][1]/x;
//	for(i=1;i<=n;++i){
//		
//	}
//}
int n,i,j; 
int main(){
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>w[i]>>h[i]>>c[i];
		if(!p1[w[i]])p1[w[i]]=++cnt;
		w[i]=p1[w[i]];
		if(!p2[h[i]])p2[h[i]]=++tot;
		h[i]=p2[h[i]];
	}
	if(n!=1ll*cnt*tot){
		return cout<<0,0;
	}
	for(i=1;i<=cnt;++i){
		for(j=0;j<=tot;++j)a[i].push_back(0);
	}
	for(i=1;i<=n;++i)a[w[i]][h[i]]=c[i];
	for(i=1;i<=cnt;++i){
		for(j=1;j<=tot;++j){
			if((a[i][j]%M)*(a[1][1]%M)%M!=(a[i][1]%M)*(a[1][j]%M)%M||
			(a[i][j]%MM)*(a[1][1]%MM)%MM!=(a[i][1]%MM)*(a[1][j]%MM)%MM){
				return cout<<0,0;
			}
		}
	}
	for(i=1;i<=tot;++i)c1=gcd(c1,a[1][i]);
	for(i=1;i<=cnt;++i)c2=gcd(c2,a[i][1]);
	for(i=1;1ll*i*i<a[1][1];++i){
		if(c1%i==0&&c2%(a[1][1]/i)==0){
			++ans;
		}
		if(c2%i==0&&c1%(a[1][1]/i)==0){
			++ans;
		}
	}
	if(1ll*i*i==c1&&c1%i==0&&c2%(a[1][1]/i)==0)++ans;
	cout<<ans;
}