#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=1e5+9;
int n;
int a[M];
ll b[M];
ll sum=0,f[109],s[109];
void work(){
	sum=0;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		sum+=a[i];
		b[i]=0;
	}
	int p=-1;
	for(int i=0;i<=60;++i){
		if(sum==s[i])p=i;
	}
	if(p==-1){
		puts("NO");
		return;
	}
	ll rex=0;
	bool flag=0;
	for(int i=1;i<=n;++i){
		ll x=a[i];
		for(int j=p;j>=0;--j){
			if(x>=f[j]){
				x-=f[j];
				b[i]|=1ll<<j;
			}
		}
		if(x){
			puts("NO");
			return;
		}
		if(b[i]&(b[i]>>1))flag=1;
		rex|=b[i];
	}
	ll up=(1ll<<(p+1))-1;
	if(rex==up&&!flag){
		puts("YES");
		return;
	}
	for(int o=1;o<=n;++o){
		int l=-1;
		for(int j=0;j<=p;++j){
			if(b[o]>>j&1){
				l=j;
				break;
			}
		}
		if(l&1){
			ll y=b[o];
			for(int i=0;i<l;i+=2)y|=1ll<<i;
			y^=1ll<<l;
			bool bol=0;
			if(y&(y>>1))bol=1;
			for(int i=1;i<=n;++i){
				if(i==o)continue;
				y|=b[i];
				if(b[i]&(b[i]>>1))bol=1;
			}
			if(y==up&&!bol){
				puts("YES");
				return;
			}
		}
	}
	puts("NO");
}
int main(){
	f[0]=f[1]=1;
	s[0]=1;
	s[1]=2;
	for(int i=2;i<=60;++i)f[i]=f[i-1]+f[i-2],s[i]=s[i-1]+f[i];
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
1
2
7 5
*/