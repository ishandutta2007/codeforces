#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
int mid,Q,n,a[1001010],F[1001010],l,r,ans,i;
bool check(int mid){
	int final=Q;
	for (int i=1;i<=n;i++){
		if (a[i]>final) {
			if (mid) F[i]=0,mid--;
			else if (final) F[i]=1,final--;
			else return 0;
		}
		else F[i]=1;
	}
	return 1;
}
void Main(){
	n=read();Q=read();
	for (i=1;i<=n;i++) a[i]=read();
	l=0,r=n,ans=0;
	while (l<=r){
		mid=(l+r)/2;
		if (check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	check(ans);
	for (i=1;i<=n;i++) printf("%d",F[i]);
	puts("");
	return ;
}
int main()
{
	int Testing;Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}