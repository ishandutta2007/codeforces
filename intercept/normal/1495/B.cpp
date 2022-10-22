#include<bits/stdc++.h>
using namespace std;
const int M=2e5+9;
int n,ma=0,ans=0;
int a[M],l[M],r[M];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		if(i==1||a[i]<a[i-1])l[i]=0;
		else l[i]=l[i-1]+1; 
		ma=max(ma,l[i]);
	}
	for(int i=n;i>=1;--i){
		if(i==n||a[i]<a[i+1])r[i]=0;
		else r[i]=r[i+1]+1;
		ma=max(ma,r[i]);
	}
	int ans1=0,ans2=0;
	for(int i=1;i<=n;++i)if(l[i]==ma)ans1++;
	for(int i=1;i<=n;++i)if(r[i]==ma)ans2++;
	if(ans1>=2||ans2>=2){
		printf("0\n");
		return 0;
	}
	int p=0,mi=0;
	for(int i=1;i<=n;++i){
		if(l[i]==ma&&r[i]>mi)mi=r[i],p=i;
		if(r[i]==ma&&l[i]>mi)mi=l[i],p=i;
		if(l[i]==ma&&r[i]==ma)ans++;
	}
	if(ans==1){
		if(ma&1)printf("0\n");
		else printf("1\n");
		return 0;
	}
	if(ans==0&&ans1==1&&ans2==1){
		printf("0\n");
		return 0;
	}
	if(ma==mi)printf("1\n");
	else printf("0\n");
	return 0;
}
/*
5
3 1 5 2 4
9
1 2 7 4 3 6 5 8 9
*/