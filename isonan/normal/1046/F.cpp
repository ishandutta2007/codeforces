#include <cstdio>
#include <iostream> 

int n;
long long a[200001],x;
long long ans,f;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	std::cin>>x>>f;
	for(int i=1;i<=n;i++){
		if(a[i]>x)ans+=f*((a[i]+f-1)/(x+f));
	}
	std::cout<<ans;
}