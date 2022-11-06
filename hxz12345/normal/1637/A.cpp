#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
long long a[1001010],b[1001010],n,i;
bool flag;
void Main(){
  n=read();
  for (i=1;i<=n;i++) a[i]=read(),b[i]=a[i];
  sort(b+1,b+n+1);flag=true;
  for (i=1;i<=n;i++)
      if (a[i]!=b[i]) flag=false;
  if (flag) puts("NO");
  else puts("YES");
}
int main() {
	int Testing=read();
	for (;Testing;Testing--) Main();
	return 0;
}