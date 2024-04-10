#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,a,b,n1,n2;
pair<int,int>p1[N],p2[N];
int main(){
//	freopen("2.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		if(a<b)p1[++n1]=make_pair(-a,i);
		else   p2[++n2]=make_pair( a,i);
	}
	if(n1>=n2){
		sort(p1+1,p1+n1+1);
		printf("%d\n",n1);
		for(int i=1;i<=n1;i++)printf("%d ",p1[i].second);
	}else{
		sort(p2+1,p2+n2+1);
		printf("%d\n",n2);
		for(int i=1;i<=n2;i++)printf("%d ",p2[i].second);
	}
	return 0;
}