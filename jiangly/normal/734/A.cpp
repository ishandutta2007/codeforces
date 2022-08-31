#include<cstdio>
const int N=1e5+5;
int n,ans;
char a[N];
int main(){
	scanf("%d",&n);
	scanf("%s",a+1);
	for(int i=1;i<=n;++i){
		ans+=a[i]=='A';
	}
	if(ans>n-ans){
		puts("Anton");
	}else if(ans<n-ans){
		puts("Danik");
	}else{
		puts("Friendship");
	}
	return 0;
}