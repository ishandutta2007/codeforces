#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300005;
int n;
ll s,t;
int a[N];
ll b[N],c[N];
int main(){
//	freopen("3.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%I64d",&a[i],&t);
		s+=a[i];
		b[i]=t;
		c[i]=t&-t;
	}
	if(s<0ll)for(int i=1;i<=n;i++)a[i]=-a[i];
	s=0ll;
	for(ll j=2305843009213693952ll;j>0ll;j>>=1){
		t=0ll;
		for(int i=1;i<=n;i++)if(c[i]==j)t+=a[i];
		if(t>0ll){
			s|=j;
			for(int i=1;i<=n;i++)if(b[i]&j)a[i]=-a[i];
		}
	}
	printf("%I64d",s);
	return 0;
}