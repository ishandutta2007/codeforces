#include<bits/stdc++.h>
std::map<int,int>b{{'T',4},{'C',6},{'O',8},{'D',12},{'I',20}};
int n,ans;
char a[20];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",a+1);
		ans+=b[a[1]];
	}
	printf("%d\n",ans);
	return 0;
}