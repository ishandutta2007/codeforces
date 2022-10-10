#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=1000010;
int i,j,k,n,m,T,a[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+1+n);
		int Sum=0,p=-1;
		for(i=1;i<=n;i++){
			Sum+=a[i];
			if(Sum==m)p=i;
		}
		if(p==n)puts("NO");
		else{
			puts("YES");
			for(i=1;i<=n;i++){
				printf("%d ",p==i?a[i+1]:(p==i-1?a[i-1]:a[i]));
			}puts("");
		}
	}
	return 0;
}