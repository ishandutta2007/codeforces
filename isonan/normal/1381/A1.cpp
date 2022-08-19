#include <cstdio>
#include <vector>

int a[100001],b[100001],t,n,l,r;
bool rev,tot;
std::vector<int>ans;
int get(int x){
	if(rev)return a[r-x+1]^tot;
	return a[l+x-1]^tot;
}
void pop(){
	if(rev)++l;
	else --r;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		rev=tot=0,l=1,r=n;
		for(int i=1;i<=n;i++)scanf("%1d",a+i);
		for(int i=1;i<=n;i++)scanf("%1d",b+i);
		ans.clear();
		for(int i=n;i;i--){
//			printf("%d %d %d %d %d\n",i,get(i),get(1),l,r);
			if(get(i)==b[i]){
				pop();
				continue;
			}
			if(get(1)!=b[i]){
				ans.push_back(i);
				rev^=1;
				tot^=1;
			}
			else{
				ans.push_back(1);
				ans.push_back(i);
				rev^=1;
				tot^=1;
			}
			pop();
		}
		printf("%d ",ans.size());
		for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);putchar('\n');
	}
}