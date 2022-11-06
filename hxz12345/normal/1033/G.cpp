//GGGGGGGGGGGGGGG
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
long long i,j,tot,n,m,a[1001010],now,b[1001010],lft,rit,F1,F2,F3;
int main()
{
	n=read();m=read();
	for (i=1;i<=n;i++) a[i]=read();
	//F1 F2 
	for (now=3;now<=2*m;now++){
		for (i=1;i<=n;i++) b[i]=a[i] % now;
		sort(b+1,b+n+1);
		for (i=0;i<n;i++) { //itype1 
			if ((n-i) % 2==0){
				lft=b[i]+1;//t-a<=b[i+1]<2*a
				lft=max(max(now-b[i+1],(b[i+1]/2)+1),lft);
				lft=max(max(now-b[n],(b[n]/2)+1),lft);
				lft=max(lft,now-m);
				rit=(now+1)/2-1;
				if (lft<=rit) F2+=(rit-lft+1);
				//bn3 
				//(b[i+1]/2)<a
			}
			// 
			if ((n-i) % 2==1){
				lft=b[i]+1;
				if (i+1!=n) lft=max(max(now-b[i+1],(b[i+1]/2)+1),lft);
				else lft=max(lft,now-b[n]);
				if (n-1!=i)lft=max(max(now-b[n-1],(b[n-1]/2)+1),lft);
				lft=max(lft,now-m);
				rit=(now+1)/2-1;
				if (lft<=rit) F1+=(rit-lft+1);
			}
	    }
	lft=b[n]+1;rit=(now+1)/2-1;
	lft=max(lft,now-m);
	if (lft<=rit) F2+=rit-lft+1;
	}F1*=2;F2*=2;
	for (i=1;i<=m;i++){
		tot=0;
		for (j=1;j<=n;j++) tot+=a[j]/i;
		if (tot&1) F1++;else F2++;
	}
	F3=(m*m-F1-F2)/2;
	printf("%lld %lld %lld %lld\n",F3,F3,F1,F2);
	return 0;
}