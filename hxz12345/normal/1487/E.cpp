#include <bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
vector<long long> edge1[1001010],edge2[1001010],edge3[1001010];
long long nn,a[1001010],b[1001010],bb[1001010],x,y,m3,w,j,cc[1001010],dd[1001010],d[1001010],c[1001010],n1,n2,n3,n4,m1,m2,i;
long long ans,e[1001010],val1[1001010],val2[1001010],VAL[1001010];
bool flag1,flag,flag2,flag3,exist1[1001010],exist2[1001010],coulddo[1001001];
int main()
{
	n2=read();n1=read();n3=read();n4=read();
    for (i=1;i<=n2;i++) b[i]=read(),bb[i]=b[i];
    
    for (i=1;i<=n1;i++) a[i]=read();
    sort(bb+1,bb+n2+1);
    for (i=1;i<=n3;i++) c[i]=read();
    for (i=1;i<=n4;i++) d[i]=read(),dd[i]=d[i];
    sort(dd+1,dd+n4+1);
    m1=read();
    for (i=1;i<=m1;i++)
        { 
           x=read();y=read();
           edge1[y].push_back(x);
		}
	m2=read();
    for (i=1;i<=m2;i++)
        { 
           x=read();y=read();
           edge2[x].push_back(y);
		}m3=read();
    for (i=1;i<=m3;i++)
        { 
           x=read();y=read();
           edge3[x].push_back(y);
	     }
	flag1=false;flag2=false;flag3=false;
    for (i=1;i<=n1;i++)
       if (edge1[i].size()!=n2)
        { 
        exist1[i]=true;
        w=0;
             for (j=0;j<edge1[i].size();j++)
                e[++w]=b[edge1[i][j]];
		    sort(e+1,e+w+1);
		for (j=1;j<=w;j++)
		   if (e[j]!=bb[j])
		        break;
		val1[i]=bb[j];
		}
	for (i=1;i<=n3;i++)
       if (edge3[i].size()!=n4)
        { 
        coulddo[i]=true;
        w=0;
             for (j=0;j<edge3[i].size();j++)
                e[++w]=d[edge3[i][j]];
		sort(e+1,e+w+1);
		for (j=1;j<=w;j++)
		   if (e[j]!=dd[j])
		        break;
		VAL[i]=dd[j]+c[i];
		}
	nn=0;
	for (i=1;i<=n3;i++) 
	    if (coulddo[i])
	        { 
	        nn++;cc[nn]=VAL[i];
			}
	sort(cc+1,cc+nn+1);
	for (i=1;i<=n1;i++)
       if (edge2[i].size()!=n3)
        { 
        w=0;
             for (j=0;j<edge2[i].size();j++)
            if (coulddo[edge2[i][j]])
                e[++w]=VAL[edge2[i][j]];
        if (w==nn) continue;
        exist2[i]=true;
		sort(e+1,e+w+1);
		for (j=1;j<=w;j++)
		   if (e[j]!=cc[j])
		        break;
		val2[i]=cc[j];
		}
	flag=false;
	ans=9e18;
	for (i=1;i<=n1;i++)
	   if (exist1[i]&&exist2[i])
	     flag=true,ans=min(ans,a[i]+val1[i]+val2[i]);
	if (flag==false) puts("-1");
	else printf("%lld\n",ans);
	return 0;
}