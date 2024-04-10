#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e6+10;
const int maxv=1e9;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char get(){
	char ch=getchar();
	while(ch<'a'||ch>'z') ch=getchar();
	return ch;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,cnt=1;
char s[N];
int a[N],b[N];
int f[N];
int find(int x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main(){
	cin>>n;
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		f[i]=i;
		if(s[i]=='1') a[i]=1;
		else if(s[i]=='0')b[i]=1;
		a[i]=a[i-1]+a[i];
		b[i]=b[i-1]+b[i];
	}
	f[n+1]=n+1;
	int x,y,ans;
	for(int i=1;i<=n;++i){
		if(i==1){
			printf("%d ",n);continue;
		}
		ans=0;
	//	cout<<endl<<"i "<<i<<endl;
		for(int j=1;j<=n;){
			j=find(j);
		//	if(i==3) cout<<"j "<<j<<endl;
			if(j+i-1>n) break;
			
			x=a[j+i-1]-a[j-1];
			y=b[j+i-1]-b[j-1];
			if(x&&y) {
				f[j]=j+1;
				++j;
			}
			else{
				++ans;
				j=j+i;
			}
		}
		printf("%d ",ans);
	}
	puts("");
	return 0;
}