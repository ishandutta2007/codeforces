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
string S[22];
struct node{long long val,id;} A[2001010],b[2001010];
long long sta,now,ans,Val[2001010],f[2001010][2],n,i,up,val,final,j,w,lim[2001010],tagl[2001010],tagr[2001010],l,lft,rit,All[2001010],fre[2001010];
int F[2001010][22];
bool cmp(node a,node b){return a.val<b.val;}
int main()
{
	n=read();
	for (i=1;i<=n;i++) cin>>S[i];
    for (i=1;i<=n;i++){
    	up=S[i].size();lim[i]=1e9;val=0;
    	for (j=0;j<up;j++)
    	    {
    	    if (S[i][j]=='(') val++;else val--;lim[i]=min(lim[i],val);
			}
    	All[1<<(i-1)]=val;
    	
	}
	final=(1<<n)-1;
	for (i=1;i<=final;i++) A[i].val=A[i^(i&-i)].val+All[i&-i];
	for (i=1;i<=final;i++) fre[i]=A[i].val;
	for (i=1;i<=final;i++) A[i].id=i;
	sort(A+1,A+final+1,cmp);
	for (i=1;i<=n;i++){w=0;
		for (j=1;j<=final;j++) 
		    if ((A[j].val>=0)&&((A[j].id&(1<<(i-1)))==0))
                   {
 		           b[++w].val=A[j].val,b[w].id=A[j].id;
 		           if (tagl[A[j].val]==0) tagl[A[j].val]=w;
 		           tagr[A[j].val]=w;
 		           }
 		ans=0;up=S[i].size();
 		l=1;
 		for (j=0;j<up;j++){
 			if (S[i][j]=='(') ans++;else ans--;
 			while ((b[l].val+ans<0)&&(l<=w)) l++;
 			if (ans<=0) 
			     {
				 lft=max(tagl[-ans],l);rit=tagr[-ans];
				 if (lft<=rit) Val[lft]++,Val[rit+1]--;
			     }
		 }
		 Val[w+1]=0;
	   for (j=1;j<=w;j++) Val[j]=Val[j-1]+Val[j];
	   for (j=1;j<=w;j++)
	        F[b[j].id][i]=Val[j],Val[j]=0;
 	   for (j=1;j<=final;j++) 
		    if ((A[j].val>=0)&&((A[j].id&(1<<(i-1)))==0))
                   tagl[A[j].val]=tagr[A[j].val]=0;
	}
	for (i=1;i<=final;i++) f[i][0]=f[i][1]=-1e9;
	for (i=1;i<=n;i++){
		up=S[i].size();val=0;f[1<<(i-1)][1]=0;
		for (j=0;j<up;j++)
		   {
		   	if (S[i][j]=='(') val++;else val--;
		   	if (val<0){
		   		f[1<<(i-1)][0]=f[1<<(i-1)][1];
		   		f[1<<(i-1)][1]=-1e9;break;
			   }
			if (val==0) 
			    {
				f[1<<(i-1)][1]++;
	             }
		   }
	 }
	for (sta=1;sta<final;sta++)
	    for (i=1;i<=n;i++)
	        if ((sta&(1<<(i-1)))==0)
	             {
	             	    now=sta^(1<<(i-1));
	             	    if (fre[sta]+lim[i]>=0)
	             	         {
	             	         	  f[now][0]=max(f[now][0],f[sta][0]);
	             	         	  f[now][1]=max(f[now][1],f[sta][1]+F[sta][i]);
							  }
						else {
							f[now][0]=max(f[now][0],max(f[sta][0],f[sta][1]+F[sta][i]));
						}
				 }
	printf("%d\n",max(f[final][1],f[final][0]));
	return 0;
}