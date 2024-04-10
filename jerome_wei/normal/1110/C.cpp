#include<bits/stdc++.h>
using namespace std;
int T;
int a;
int main()
{
	cin>>T;
	while(T--){
		scanf("%d",&a);
		int l=0;
		while((1<<l)<=a)++l;
		if(a==(1<<l)-1){
			int tot=(1<<l)-1;
			int ans=tot;
			for(int i=2;i*i<=tot;i++){
				if(tot%i==0){
					ans=i;break;
				}
			}
			cout<<tot/ans<<endl;
			continue;
		}
		printf("%d\n",(1<<l)-1);
	}
}