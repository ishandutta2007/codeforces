#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	int ans=0;
	for(int i=2;i<n;++i){
		ans+=1*i*(i+1);
	}
	printf("%d\n",ans);
	return 0;
}