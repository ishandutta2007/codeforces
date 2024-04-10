#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,a[1100000]; pii v[2100000];
void upd(pii &x,int v){
	if (x.first<v) x.second=x.first,x.first=v;
	else if (x.second<v&&v<x.first) x.second=v;
}
void FWT(int n){
	for (int j=0;j<=20;j++)
		for (int i=0;i<n;i++)
			if (!((i>>j)&1)){
				upd(v[i],v[i|(1<<j)].first);
				upd(v[i],v[i|(1<<j)].second);
			}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		v[a[i]].second=v[a[i]].first; v[a[i]].first=i;
	}
	FWT(1<<21); int ans=0;
	for (int i=1;i<=n-2;i++){
		int now=0,res=0;
		for (int j=20;j>=0;j--){
			if ((a[i]>>j)&1){ res|=(1<<j); continue;}
			if (v[now|(1<<j)].second>i){ res|=(1<<j); now|=(1<<j);}
		}
		ans=max(ans,res);
	}
	printf("%d\n",ans);
	return 0;
}