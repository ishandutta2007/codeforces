#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=3e7+9;
const int B=309;
int n,ans=1;
int a[M],b[M<<1],c[M];
void work(){
	for(int i=0;i<=B;++i){
		for(int j=1;j<=n;++j)b[a[j]-i*j]++,ans=max(ans,b[a[j]-i*j]);
		for(int j=1;j<=n;++j)b[a[j]-i*j]--;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=min(B*2,i-1);++j){
			if((a[i]-a[i-j])%j==0&&a[i]>=a[i-j]){
				int x=(a[i]-a[i-j])/j;
				b[x]++;
				ans=max(ans,b[x]+1);
			}
		}
		for(int j=1;j<=min(B*2,i-1);++j){
			if((a[i]-a[i-j])%j==0&&a[i]>=a[i-j]){
				int x=(a[i]-a[i-j])/j;
				b[x]--;
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]+=M;
	work();
	for(int i=1;i<=n/2;++i)swap(a[i],a[n-i+1]);
	work();
	printf("%d\n",n-ans);
	return 0;
}