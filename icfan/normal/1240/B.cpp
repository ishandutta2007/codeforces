#include <cstdio>
#include <algorithm>
using namespace std;
#define Maxn 300000
template<typename Elem>
void read(Elem &a){
	a=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		a=(a<<1)+(a<<3)+(c^48);
		c=getchar();
	}
}
int n;
int a[Maxn+5];
int left[Maxn+5],right[Maxn+5];
int f[Maxn+5],g[Maxn+5];
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int t;
	read(t);
	int ans;
	int num;
	while(t--){
		read(n);
		num=0;
		for(int i=1;i<=n;i++){
			read(a[i]);
			if(left[a[i]]==0){
				left[a[i]]=i;
				right[a[i]]=i;
				num++;
			}
			else{
				right[a[i]]=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(left[i]==0){
				f[i]=f[i-1];
				right[i]=right[i-1];
				continue;
			}
			if(left[i]>right[i-1]){
				f[i]=f[i-1]+1;
			}
			else{
				f[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(left[i]==0){
				right[i]=0;
			}
		}
		for(int i=n;i>0;i--){
			if(right[i]==0){
				g[i]=g[i+1];
				left[i]=left[i+1];
				continue;
			}
			if(right[i]<left[i+1]){
				g[i]=g[i+1]+1;
			}
			else{
				g[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(right[i]==0){
				left[i]=0;
			}
		}
		ans=num;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				continue;
			}
			if(right[a[i]]<left[a[i+1]]){
				ans=mn(ans,num-f[a[i]]-g[a[i+1]]);
			}
			else{
				ans=mn(ans,num-f[a[i]]);
				ans=mn(ans,num-g[a[i+1]]);
			}
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++){
			left[i]=right[i]=0;
			f[i]=g[i]=0;
		}
	}
	return 0;
}