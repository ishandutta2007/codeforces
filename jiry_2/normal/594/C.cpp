#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct point{
	int x,y;
	void scan(){
		int k1,k2,k3,k4; scanf("%d%d%d%d",&k1,&k2,&k3,&k4);
		x=k1+k3; y=k2+k4;
	}
}A[110000];
int a[110000],b[110000],n,K,ans;
int compare(int k1,int k2){
	return A[k1].x<A[k2].x;
}
int compare2(int k1,int k2){
	return A[k1].y<A[k2].y;
}
int pd[110000],sign;
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++) A[i].scan();
	for (int i=1;i<=n;i++) a[i]=i,b[i]=i;
	sort(a+1,a+n+1,compare);
	sort(b+1,b+n+1,compare2);
	long long ans=2e18;
	for (int l=1;l<=min(n,K+1);l++)
		for (int r=max(l,n-K);r<=n;r++)
			for (int d=1;d<=min(n,K+1);d++)
				for (int u=max(d,n-K);u<=n;u++){
					sign++; int num=0;
					for (int i=1;i<l;i++) if (pd[a[i]]!=sign) pd[a[i]]=sign,num++;
					for (int i=r+1;i<=n;i++) if (pd[a[i]]!=sign) pd[a[i]]=sign,num++;
					for (int i=1;i<d;i++) if (pd[b[i]]!=sign) pd[b[i]]=sign,num++;
					for (int i=u+1;i<=n;i++) if (pd[b[i]]!=sign) pd[b[i]]=sign,num++;
					if (num<=K){
						int k1=max(A[a[r]].x-A[a[l]].x,1),k2=max(A[b[u]].y-A[b[d]].y,1);
						if (k1&1) k1++;
						if (k2&1) k2++;
					//	cout<<"fa "<<l<<" "<<r<<" "<<d<<" "<<u<<" "<<k1<<" "<<k2<<endl;
						k1/=2; k2/=2; ans=min(ans,1ll*k1*k2);
					}
				}
	cout<<ans<<endl;
	return 0;
}