#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int T,n,a[510],b[510];
pii x[510],y[510];
bool check(){
	int m=(n>>1)+1;
	if ((n&1)&&a[m]!=b[m]) return false;
	for (int i=1;i<m;i++){
		x[i]=pii(min(a[i],a[n-i+1]),max(a[i],a[n-i+1]));
		y[i]=pii(min(b[i],b[n-i+1]),max(b[i],b[n-i+1]));
	}
	sort(x+1,x+m); sort(y+1,y+m);
//	for (int i=1;i<m;i++) cerr<<x[i].first<<' '<<x[i].second<<endl;
//	for (int i=1;i<m;i++) cerr<<y[i].first<<' '<<y[i].second<<endl;
	for (int i=1;i<m;i++)
		if (x[i]!=y[i]) return false;
	return true;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) scanf("%d",&b[i]);
		if (check()) puts("Yes");
		else puts("No");
	}
	return 0;
}