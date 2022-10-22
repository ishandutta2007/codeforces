#include<iostream>
#define int long long
using namespace std;
const int N=2e5+9;
char a[N],b[N];
int r[N],l[N],ans;
inline int read(){
   int x=0,f=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
   return x*f;
}
signed main(){
	int n=read(),m=read();
	scanf("%s",a+1);
	scanf("%s",b+1);
	int now=1;
	for(int i=1;i<=n;i++){
		if(b[now]==a[i])l[now]=i,now++;
		if(now==m+1)break;
	}
	now=m;
	for(int i=n;i>=1;i--){
		if(b[now]==a[i])r[now]=i,now--;
		if(!now)break;
	}
	for(int i=1;i<m;i++){
		ans=max(ans,r[i+1]-l[i]);
	}
	cout<<ans<<endl;
	return 0;
}