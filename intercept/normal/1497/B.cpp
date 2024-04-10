#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int M=1e5+9;
int n,m;
int a[M],b[M];
void work(){
	int ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),a[i]%=m;
	for(int i=0;i<=m;++i)b[i]=0;
	for(int i=1;i<=n;++i)b[a[i]]++;
	if(b[0])ans++;
	for(int i=1;i<=(m-1)/2;++i){
		if(!b[i]&&!b[m-i])continue;
		int x=b[i],y=b[m-i];
		if(x<y)swap(x,y);
		if(x==y)ans++;
		else ans+=x-y;
	}
	if(m%2==0&&b[m/2])ans++;
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
1
5 7
0 1 2 2 2
*/