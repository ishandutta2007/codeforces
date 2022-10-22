#include<bits/stdc++.h>
using namespace std;
const int M=1e5+9;
int n,m;
int a[309],id[309],b[309];
void add(int i){
	for(;i<=m;i+=i&-i)b[i]++;
}
int sum(int i,int rex=0){
	for(;i;i-=i&-i)rex+=b[i];
	return rex;
}
bool cmp(int l,int r){
	return a[l]==a[r]?l>r:a[l]<a[r];
}
void work(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)scanf("%d",&a[i]),id[i]=i,b[i]=0;
	sort(id+1,id+m+1,cmp);
	int ans=0;
	for(int i=1;i<=m;++i){
		ans+=sum(id[i]);
		add(id[i]);
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	for(scanf("%d",&T);T;--T)work();
	return 0;
}