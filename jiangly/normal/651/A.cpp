#include<bits/stdc++.h>
int a_1,a_2,ans;
int main(){
	scanf("%d%d",&a_1,&a_2);
	while(a_1>0&&a_2>0){
		if(a_1>a_2){
			std::swap(a_1,a_2);
		}
		++a_1;
		a_2-=2;
		if(a_1>=0&&a_2>=0)
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}