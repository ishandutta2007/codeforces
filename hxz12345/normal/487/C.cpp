#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long ans,inv[100101],n,i;
bool check(int n){
	for (int i=2;i<=sqrt(n);i++)
	    if (n % i==0) return false;
	return true;
}
int main(){n=read();
	if (n==1) {printf("YES\n1\n");return 0;}
	if (n==2) {printf("YES\n1\n2\n");return 0;}
	if (n==3) {printf("YES\n1\n2\n3\n");return 0;}
	if (n==4) {printf("YES\n1\n3\n2\n4\n");return 0;}
	if (check(n)==false) {puts("NO");return 0;}
	puts("YES");inv[1]=1;
	for (i=2;i<=n;i++) inv[i]=(n-n/i)*inv[n % i] % n;inv[n]=n;ans=1;
	for (i=1;i<n;i++) printf("%lld\n",inv[i]*inv[ans] % n),ans=ans*inv[i] % n*inv[ans] % n;printf("%lld\n",n);
	return 0;
}