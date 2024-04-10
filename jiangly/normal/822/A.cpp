#include<bits/stdc++.h>
int a,b;
template<class T>const T&min(const T&a,const T&b){
	return a<b?a:b;
}
int main(){
	scanf("%d%d",&a,&b);
	a=min(a,b);
	b=1;
	for(int i=1;i<=a;++i)
		b*=i;
	printf("%d\n",b);
	return 0;
}