#include<iostream>
#define int long long
using namespace std;
const int N=1e5+9;
inline int read(){
   int x=0,f=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
   return x*f;
}
int t,a[N];
int val[N],id[N];
signed main(){
	t=read();
	while(t--){
		int n=read();
		for(int i=1;i<=n;i++){
			val[i]=val[i-1],id[i]=id[i-1];
			a[i]=read();
			if(a[i]>val[i])val[i]=a[i],id[i]=i;
		}
		int now=n;
		while(now){
			int nt=id[now];
			for(int i=nt;i<=now;i++)
				printf("%d ",a[i]);
			now=nt-1;
		}
		puts("");
	}
	return 0;
}