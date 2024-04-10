#include<iostream>
#define int long long
using namespace std;
inline int read(){
   int x=0,f=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
   return x*f;
}

int t;
signed main(){
	t=read();
	while(t--){
		int p=read(),a=read(),b=read(),c=read();
		if(p%a==0||p%b==0||p%c==0)puts("0");
		else {
			printf("%lld\n",min(p/a*a+a-p,min(p/b*b+b-p,p/c*c+c-p)));
		}
		
	}
	return 0;
}