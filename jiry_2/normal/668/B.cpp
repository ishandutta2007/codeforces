#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int num1=0,num2=0,pre=1,n,m,ans[1100000];
int main(){
	scanf("%d%d",&n,&m);
	for (;m;m--){
		int k1,k2; scanf("%d",&k1);
		if (k1==1){
			scanf("%d",&k2);
			k2=(k2+n)%n;
			num1=(num1+k2)%n;
		} else if (k1==2){
			k2=num1&1; 
			if (k2==pre) num2=(num2+n-1)%n,pre^=1; else num2=(num2+1)%n,pre=k2;
		}
	}
//	cout<<num1<<" "<<num2<<endl;
	for (int i=1;i<=n;i++){
		int go=0;
		if (i&1) go=(num1+num2)%n; else go=(num1-num2+n)%n;
		int ne=(i-1+go)%n+1;
		ans[ne]=i;
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]); printf("\n");
	return 0;
}