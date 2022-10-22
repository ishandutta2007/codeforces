#include<bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tii;
int n,d; tii a[510000];
int main(){
	scanf("%d%d",&n,&d); int x,y;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		a[i]=tii(max(x,y),x,y);
	}
	sort(a+1,a+n+1);
	int ans=0;
	for (int i=1;i<=n;i++)
		if (d<=get<1>(a[i])) d=max(d,get<2>(a[i])),ans++;
	printf("%d\n",ans);
	return 0;
}