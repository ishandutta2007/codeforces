#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int l,r,x[610000],n,K;
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	long long num=0;
	for (int i=1;i<=n;i++) num+=x[i];
	int l=1,r=1e9+1,ansl=1;
	while (l<r){
		int mid=l+r>>1;
		long long tot=0;
		for (int i=1;i<=n;i++)
			if (mid>=x[i]) tot+=mid-x[i];
		if (tot>K) r=mid;
		else {
			l=mid+1; ansl=mid;
		}
	}
	l=ansl,r=1e9+1; int ansr=r;
	while (l<r){
		int mid=l+r>>1;
		long long tot=0;
		for (int i=1;i<=n;i++)
			if (mid<=x[i]) tot+=x[i]-mid;
		if (tot>K) l=mid+1;
		else {
			r=mid; ansr=mid;
		}
	}
	if (ansl==ansr&&num%n) ansr++;
	printf("%d\n",ansr-ansl);
	return 0;
}