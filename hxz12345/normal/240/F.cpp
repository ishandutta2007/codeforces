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
struct SegmentTreee{
	int sum,tag;
} tree[27][401010];
int sum,L,R,tag,j,fre[1001010],i,l,r,n,Testing;
char S[1001010];
void pushup(int sta,int x)
{
	tree[sta][x].sum=tree[sta][x*2].sum+tree[sta][x*2+1].sum;
}
void pushdown(int sta,int x,int l,int r){
	if (tree[sta][x].tag!=-1)
	    { 
	    int mid=(l+r)/2;
	    tree[sta][x*2].sum=tree[sta][x].tag*(mid-l+1);tree[sta][x*2+1].sum=tree[sta][x].tag*(r-mid);
	    tree[sta][x*2].tag=tree[sta][x].tag;tree[sta][x*2+1].tag=tree[sta][x].tag;tree[sta][x].tag=-1;
		}
}
void build(int sta,int x,int l,int r)
{
	tree[sta][x].sum=0;
	tree[sta][x].tag=-1;
	if (l==r) return ;
	int mid=(l+r)/2;
	build(sta,x*2,l,mid);build(sta,x*2+1,mid+1,r);
}
void modify(int sta,int x,int l,int r,int tl,int tr,int val)
{
	if ((l>=tl)&&(r<=tr))
	    {  
	        tree[sta][x].sum=val*(r-l+1);tree[sta][x].tag=val;return;
		}
	pushdown(sta,x,l,r);
	int mid=(l+r)/2;
	if (mid>=tl) modify(sta,x*2,l,mid,tl,tr,val);
	if (mid<tr) modify(sta,x*2+1,mid+1,r,tl,tr,val);
	pushup(sta,x);
}
int query(int sta,int x,int l,int r,int tl,int tr)
{
	if ((l>=tl)&&(r<=tr))  
	   return tree[sta][x].sum;
	pushdown(sta,x,l,r);
	int mid=(l+r)/2;int ans=0;
	if (mid>=tl) ans+=query(sta,x*2,l,mid,tl,tr);
	if (mid<tr) ans+=query(sta,x*2+1,mid+1,r,tl,tr);
	pushup(sta,x);
	return ans;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n=read();Testing=read();
	scanf("%s",S+1);
	for (i=0;i<26;i++) build(i,1,1,n);
	for (i=1;i<=n;i++) modify(S[i]-'a',1,1,n,i,i,1);
	for (;Testing;Testing--)
	    { 
	        l=read();r=read();sum=0;
	        for (i=0;i<26;i++)
	            {
	            fre[i]=query(i,1,1,n,l,r);
	            sum+=fre[i]&1;
	            }
	        if (sum==0)
	            {
	                   L=l;R=r;
	                   for (i=0;i<26;i++) modify(i,1,1,n,L,R,0);
	            	   for (i=0;i<26;i++)
	            	      if (fre[i])
	            	         {
	            	            modify(i,1,1,n,L,L+(fre[i]/2)-1,1);
								modify(i,1,1,n,R-(fre[i]/2)+1,R,1);
								L+=fre[i]/2;R-=fre[i]/2;
							 }
				}
			if (sum==1)
			   {  
			       tag=0;
			       for (i=0;i<26;i++)
			           if (fre[i]&1)
			              tag=i;
			        fre[tag]--;
			        L=l;R=r;
			       for (i=0;i<26;i++) modify(i,1,1,n,L,R,0);
			       for (i=0;i<26;i++)
			          if ((fre[i]))
			              { 
			                    modify(i,1,1,n,L,L+(fre[i]/2)-1,1);
								modify(i,1,1,n,R-(fre[i]/2)+1,R,1);
								L+=fre[i]/2;R-=fre[i]/2;
						  }
				   modify(tag,1,1,n,L,R,1);
			   }
		}
	for (i=1;i<=n;i++)
	    for (j=0;j<26;j++)
	       if (query(j,1,1,n,i,i)==1)
	           printf("%c",j+'a');
	puts("");
	return 0;
}