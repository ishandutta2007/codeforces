#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<unordered_map>
using namespace std;
int n,p[110000],an[110000];
unordered_map<int,int>M;
int check(int lim){
	M.clear();
	for (int i=1;i<=n;i++){
		int now=p[i];
		while (now&&(now>lim||M[now]==1)) now>>=1;
		if (now==0) return 0;
		M[now]=1; an[i]=now;
	}
	return 1;
}
int main(){
	int l=0,r=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&p[i]); r=max(r,p[i]);
	}
	r++; int ans=0;
	while (l<r){
		int mid=l+r>>1;
		if (check(mid)){
			ans=mid; r=mid;
		} else l=mid+1;
	}
	check(ans);
	for (int i=1;i<=n;i++) printf("%d ",an[i]); printf("\n");
	return 0;
}