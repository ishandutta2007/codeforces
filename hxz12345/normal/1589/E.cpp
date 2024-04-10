#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
struct node{
	long long val,id;
} B[1001010];
vector<int> V[1001010];
long long now,l,r,act,w,L,R,mid,j,st1[301010][22],st2[301010][22],lg[1001010],A[1001010],c[1001010],lim[1001010],pre1[1001010],pre2[1001010],b[1001010],sum,ans,a[1001010],lft,rit,Testing,n,i;
bool cmp(node a,node b){
	return ((a.val<b.val)||((a.val==b.val)&&(a.id<b.id)));
}
long long find_min(long long l,long long r){
	long long len=lg[r-l+1];
	return min(st1[l][len],st1[r-(1<<len)+1][len]);
}

long long find_max(long long l,long long r){
	long long len=lg[r-l+1];
	return max(st2[l][len],st2[r-(1<<len)+1][len]);
}
int main(){
	for (i=2;i<=1000000;i++) lg[i]=lg[i>>1]+1;
	Testing=read();
	for (;Testing;Testing--){
		n=read();sum=0;
		for (i=1;i<=n;i++) a[i]=read();
		for (i=1;i<=n;i++) {
			pre1[i]=pre1[i-1];pre2[i]=pre2[i-1];
			if (i&1) pre1[i]=pre1[i]+a[i];
			else pre2[i]=pre2[i]+a[i];
			A[i]=pre1[i]-pre2[i];
		}
	   for (i=1;i<=n;i++) 
	        {
	        	if (i&1) st1[i][0]=A[i];
	        	else st1[i][0]=1e18;
	        	if (i % 2==0) st2[i][0]=A[i];
	        	else st2[i][0]=-1e18;
		    }
	   for (j=1;j<=lg[n];j++)
	      for (i=1;i<=n-(1<<j)+1;i++)
	          {
	          	st1[i][j]=min(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
	          	st2[i][j]=max(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
			  }
		lim[n+1]=n+1;
		for (lft=1;lft<=n;lft++)
		   {
		   	if (a[lft]==0) sum++;
		   	ans=0;
		   	L=lft+1;R=n;lim[lft]=lft;
		   	while (L<=R){
		   		mid=(L+R)/2;
		   		if ((find_min(lft+1,mid)>=A[lft-1])&&(find_max(lft+1,mid)<=A[lft-1])){
		   			lim[lft]=mid;L=mid+1;
				   }
				else R=mid-1;
			   }
		   }
	for (i=1;i<=n;i++) B[i].val=A[i],B[i].id=i;
	n++;B[n].val=0;B[n].id=0;
	sort(B+1,B+n+1,cmp);
	w=0;B[0].val=2e18;
	for (i=1;i<=n;i++)
	   if (B[i].val!=B[i-1].val){
	   	w++;V[w].push_back(B[i].id);
	   }
	else V[w].push_back(B[i].id);sum=0;
	for (now=1;now<=w;now++){
		l=1;act=0;
		for (i=0;i<V[now].size();i++) c[++act]=V[now][i];
		for (i=1;i<=act;i++){
			while ((l<=act)&&(lim[c[i]+1]>=c[l])) l++;
			sum+=l-i-1;
		}
	}
	for (i=1;i<=w;i++) V[i].clear();
	printf("%lld\n",sum);
	}
return 0;
}