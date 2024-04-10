#include<bits/stdc++.h>
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
template<class T>const T&max(const T&a,const T&b){
	return a>b?a:b;
}
int y,w;
int main(){
	scanf("%d%d",&y,&w);
	int a=7-max(y,w),b=6,g=gcd(a,b);
	printf("%d/%d\n",a/g,b/g);
	return 0;
}