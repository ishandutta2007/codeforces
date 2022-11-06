#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long Testing,n,a[1001010],b[1001010],i;
bool flag;
int main(){
	Testing=read();
	for (;Testing;Testing--){
	n=read();
	for (i=1;i<=n;i++) a[i]=read();
	for (i=1;i<=n;i++) b[i]=read();
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	flag=false;
	for (i=1;i<=n;i++)
	    if ((b[i]>a[i]+1)||(b[i]<a[i])){
	    	puts("NO");flag=true;break;
		}
	if (flag==false) puts("YES");
    }
return 0;
}