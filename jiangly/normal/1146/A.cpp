#include<bits/stdc++.h>
const int N=50+5;
int n,ans;
char a[N];
template<class T>inline T min(const T&a,const T&b){
	return a<b?a:b;
}
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=1;i<=n;++i){
		ans+=a[i]=='a';
	}
	printf("%d\n",min(2*ans-1,n));
	return 0;
}