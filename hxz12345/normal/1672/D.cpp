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
const int N=2e5+5;
int n,i,a[N],b[N],A[N],B[N],l,r,fre[N];
void Main(){
	n=read();memset(fre,0,sizeof(fre));
	for (i=1;i<=n;i++) a[i]=read(),A[i]=a[i];
	for (i=1;i<=n;i++) b[i]=read(),B[i]=b[i];
	sort(A+1,A+n+1);sort(B+1,B+n+1);
	for (i=1;i<=n;i++) 
	    if (A[i]!=B[i]){
	    	puts("NO");return ;
		}
	for (i=1;i<=n;i++){
		a[i]=lower_bound(A+1,A+1+n,a[i])-A;
		b[i]=lower_bound(A+1,A+1+n,b[i])-A;
	}
	l=1;r=1;
	while ((l<=n)&&(r<=n)){
		if (a[l]==b[r]) {
			l++;r++;continue;
		}
		if ((b[r]==b[r-1])&&(fre[b[r]])){
			fre[b[r]]--;r++;
		}else{
			fre[a[l]]++;l++;
		}
	}
	while (r<=n){
		if (b[r]==b[r-1]&&fre[b[r]]){
			fre[b[r]]--;r++;continue;
		}
		puts("NO");return ;
	}
	puts("YES");
	return ;
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}