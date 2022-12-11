#include <bits/stdc++.h>
using namespace std;
int T,n,m,p,k;
vector<int>a;
int main(){
	scanf("%d",&T);
	while(T--){
		a.clear();
		scanf("%d",&n);
		for(int k=1;k<=n;k*=10) if((n/k)%10!=0) a.push_back(k);
		printf("%d\n",a.size());
		for(int i=0;i<a.size();i++) printf("%d ",((n/a[i])%10)*a[i]); 
		printf("\n");
	}
}