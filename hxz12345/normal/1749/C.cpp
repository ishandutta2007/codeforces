#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((ch!='-')&&(!isdigit(ch))) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long l,r,m,n,a[1001010],b[1001010],ans,i,step,num,id,j;
bool flag;
void Main(){
	n=read();
	for (i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	ans=0;
	for (step=1;step<=n;step++){
		m=0;
		for (i=1;i<=n;i++)
		   if (a[i]<=step) b[++m]=a[i];
		r=m;l=1;flag=true;
		for (i=1;i<=step;i++){
			if (l>r) flag=false;
			while ((r>0)&&(b[r]>step-i+1)) r--;
			if (l>r) flag=false;
			r--;l++;
		}
		if (flag) ans=step;
	}
	cout<<ans<<endl;
	return ;
}
int main() {
	int Testing=read();
	for (;Testing;Testing--) Main();
	return 0;
}