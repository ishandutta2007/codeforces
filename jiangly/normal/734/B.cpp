#include<bits/stdc++.h>
int k2,k3,k5,k6;
template<class T>const T&min(const T&a,const T&b){
	return a<b?a:b;
}
int main(){
	scanf("%d%d%d%d",&k2,&k3,&k5,&k6);
	int x1=min(k2,min(k5,k6));
	k2-=x1;
	int x2=min(k2,k3);
	printf("%d\n",x1*256+x2*32);
	return 0;
}