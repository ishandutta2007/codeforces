#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
using namespace std;
const int mo=998244353,mo2=1e9+7;
const int N=2e5+5,M=5005,G=505;
int q,n;
int p[N];
int x,a,y,b;
int ans;
ll k,s[N];
int ksm(int x,int y){
	int t=1;
	for(;y;y>>=1,x=(ll)x*x%mo)if(y&1)t=(ll)t*x%mo;
	return t;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d",&q);
	for(;q--;){
		scanf("%d",&n);
		fo(i,1,n)scanf("%d",&p[i]);
		sort(p+1,p+n+1,cmp);
		fo(i,1,n)s[i]=s[i-1]+p[i];
		cin>>x>>a>>y>>b;
		if(x<y)swap(x,y),swap(a,b);
		cin>>k;
		ans=-1;
		int ga=0,gb=0,gg=0;
		fo(i,1,n){
			if(i%a==0&&i%b==0)++gg;
			else{
				if(i%a==0)++ga;
				if(i%b==0)++gb;
			}
			if(s[gg]/100*(x+y)+(s[gg+ga]-s[gg])/100*x+(s[gg+ga+gb]-s[gg+ga])/100*y>=k){
				ans=i;break;
			}
		}
		cout<<ans<<endl;
	}
}