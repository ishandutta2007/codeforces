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
bool flag;
long long yy,ff,j,V1[1001010],V2[1001010],ee,n,m,i,cnt,F1[1001010],a[1001010],b[1001010],pd[1001010][2],pu[1001010][2],sd[1001001][2],su[1001010][2],st[1001010];
void Main(){
	n=read();m=read();cnt=0;
	F1[++cnt]=1;F1[++cnt]=1000000000;
	for (i=1;i<=n;i++){
		a[i]=read(),b[i]=read();
		F1[++cnt]=a[i];if (a[i]-b[i]>=1) F1[++cnt]=a[i]-b[i];if (a[i]+b[i]<=1000000000) F1[++cnt]=a[i]+b[i];
	}
	sort(F1+1,F1+cnt+1);cnt=unique(F1+1,F1+cnt+1)-F1-1;
	for (i=1;i<=n;i++) a[i]=lower_bound(F1+1,F1+cnt+1,a[i])-F1;
	for (i=1;i<=cnt;i++){
		pd[i][0]=pd[i][1]=pu[i][0]=pu[i][1]=sd[i][0]=sd[i][1]=su[i][0]=su[i][1]=0;
		st[i]=0;
	}
	for(i=1;i<=n;i++)
		{
		ff=F1[a[i]]-b[i];if(ff>=1) ff=lower_bound(F1+1,F1+cnt+1,ff)-F1,su[ff][0]+=F1[ff],su[ff][1]++;
		ee=F1[a[i]]+b[i];if(ee<=1e9)ee=lower_bound(F1+1,F1+cnt+1,ee)-F1,pu[ee][0]-=F1[ee],pu[ee][1]++;
		pd[a[i]][0]+=b[i]+F1[a[i]];pd[a[i]][1]++;
		sd[a[i]][0]+=b[i]-F1[a[i]];sd[a[i]][1]++;st[a[i]]-=b[i];
		}
	for(i=2;i<=cnt;i++)
	   for (j=0;j<=1;j++)
	      pd[i][j]+=pd[i-1][j],pu[i][j]+=pu[i-1][j];
	for (i=cnt-1;i>=1;i--) 
	   for (j=0;j<=1;j++)
	       su[i][j]+=su[i+1][j],sd[i][j]+=sd[i+1][j];
	for(i=1;i<=cnt;i++) V1[i]=V2[i]=-0x3f3f3f3f3f3f3f3f;
	for(i=1;i<=cnt;i++)
		{
			yy=st[i]+(pu[i][0]+pu[i][1]*F1[i])+(pd[i][0]-pd[i][1]*F1[i])+(su[i][0]-su[i][1]*F1[i])+(sd[i][0]+sd[i][1]*F1[i]);
			if(yy>m) V1[i]=yy-m-F1[i],V2[i]=yy-m+F1[i];
		}
	for(i=2;i<=cnt;i++) V1[i]=max(V1[i],V1[i-1]);
	for(i=cnt-1;i>=1;i--) V2[i]=max(V2[i],V2[i+1]);
	for(i=1;i<=n;i++)
		{
		flag=true;if(b[i]<V1[a[i]]+F1[a[i]]) flag=false;if(b[i]<V2[a[i]]-F1[a[i]]) flag=false;
		if(flag) printf("1");else printf("0");
		}
	puts("");
	return ;
}
int main()
{
	int Testing;Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}