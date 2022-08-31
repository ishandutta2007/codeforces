#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

int n,a[1001],b[1001],orig[1001],fin[2000010][2],top;
void add(int x,int y){
	if(x>y)x^=y^=x^=y;
	std::swap(a[x],a[y]);
	++top;
	fin[top][0]=x;
	fin[top][1]=y;
}
bool cmp(int a,int b){return (orig[a]<orig[b])||(orig[a]==orig[b]&&a<b);}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	memcpy(b,a,sizeof a);
	memcpy(orig,a,sizeof orig);
	std::sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		std::vector<int> tem;
		for(int j=i+1;j<=n;j++)
			if(orig[i]>orig[j])tem.push_back(j);
		std::sort(tem.begin(),tem.end(),cmp);
		for(int j=tem.size()-1;~j;--j)add(i,tem[j]);
	}
	printf("%d\n",top);
	for(int i=1;i<=top;i++)printf("%d %d\n",fin[i][0],fin[i][1]);
}