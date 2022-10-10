#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=3010;
int i,j,k,n,m,a[maxn],b[maxn];
int main(){
	int T;
	cin>>T;
	while(T--){
		n=read();
		for(i=1;i<=n;i++)a[i]=read()+1,b[i]=a[i];
		sort(b+1,b+1+n);
		int Ans=1e9;
		for(i=1;i<=n;i++){
			int Num=i,ans=0;
			for(j=n;j>=1;j--)
				if(a[j]==b[Num])Num--;
			ans+=Num;
			Num=i;
			for(j=1;j<=n;j++)
				if(a[j]==b[Num])Num++;
			ans+=(n-i+1)-(Num-i);
			Ans=min(Ans,ans);
		}cout<<Ans<<endl;
		for(i=1;i<=n;i++)a[i]=b[i]=0;
	}
	return 0;
}