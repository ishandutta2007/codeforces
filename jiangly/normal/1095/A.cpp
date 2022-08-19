#include<bits/stdc++.h>
const int N=55+5;
int n;
char t[N];
int main(){
	scanf("%d",&n);
	scanf("%s",t+1);
	for(int i=1,j=1;i<=n;i+=j,++j){
		std::cout<<t[i];
	}
	return 0;
}