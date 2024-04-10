#include<cstdio>
const int N=1e5;
int n,top,ans;
int a[N],b[N];
template<class T>T min(T a,T b){
	return a<b?a:b;
}
template<class T>T max(T a,T b){
	return a>b?a:b;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",a+i);
		if(!i||a[i]!=a[i-1]){
			b[top++]=1;
		}else{
			++b[top-1];
		}
	}
	for(int i=0;i<top-1;++i){
		ans=max(ans,min(b[i],b[i+1]));
	}
	printf("%d",ans*2);
	return 0;
}