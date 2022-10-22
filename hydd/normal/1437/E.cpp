#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int n,k,a[510000],b[510000],cnt,c[510000];
int top,s[510000];
int main(){
	scanf("%d%d",&n,&k);
	a[0]=-INF; a[n+1]=INF;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]-=i;
	}
	b[0]=0; b[k+1]=n+1;
	for (int i=1;i<=k;i++) scanf("%d",&b[i]);
	bool flag=true;
	for (int i=0;i<=k;i++)
		if (a[b[i]]>a[b[i+1]]) flag=false;
	if (!flag){
		puts("-1");
		return 0;
	}
	c[++cnt]=a[b[0]];
	for (int i=0;i<=k;i++){
		for (int j=b[i]+1;j<=b[i+1]-1;j++)
			if (a[b[i]]<=a[j]&&a[j]<=a[b[i+1]]) c[++cnt]=a[j];
		c[++cnt]=a[b[i+1]];
	}
	int top=0;
	for (int i=1;i<=cnt;i++){
		// cerr<<c[i]<<' ';
		int pos=upper_bound(s+1,s+top+1,c[i])-s;
		if (pos==top+1) top++;
		s[pos]=c[i]; //cerr<<top<<endl;
	}
	printf("%d\n",n+2-top);
	return 0;
}