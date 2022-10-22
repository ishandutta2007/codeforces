/*
	Time: 2020/12/20 20:38 - 20:41
*/
#include<bits/stdc++.h>
using namespace std;
int n,a[210000];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]+=i;
	}
	sort(a+1,a+n+1);
	bool flag=true;
	for (int i=1;i<n;i++)
		if (a[i]==a[i+1]) flag=false;
	if (flag)
		for (int i=1;i<=n;i++) printf("%d ",a[i]-i);
	else puts(":(");
	return 0;
}