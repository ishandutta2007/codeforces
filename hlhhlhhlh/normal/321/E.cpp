// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=4010;
int i,j,k;
int n,m,ans,anss,ansss;
int l,r,mid;
int mp[maxn][maxn];
int read(){
	int tot=0;
	char c=getchar();
	while ((c<'0')||(c>'9'))c=getchar();
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot;
}
struct node{
	int l,r,thi;
	node(int x=0,int y=0,int z=0){ l=x; r=y; thi=z; }
}a[maxn];
struct node2{
	int x,y;
	node2(int xx=0,int yy=0){ x=xx; y=yy; }
}dp[maxn];
bool operator <(node2 a,node2 b){ return ((a.x<b.x)||((a.x==b.x)&&(a.y<b.y))); }
bool operator <=(node2 a,node2 b){ return ((a.x<b.x)||((a.x==b.x)&&(a.y<=b.y))); }
node2 operator +(node2 a,node2 b){ return node2(a.x+b.x,a.y+b.y); }
node2 work(int l,int r){
	node2 ans=dp[l];
	ans.y++; ans.x=ans.x+(mp[r][r]-mp[r][l]*2+mp[l][l])/2+mid;
	return ans;
}
int check(){
	int i,l,r,ll,rr,mid,ans;
	l=1; r=1; a[1]=node(1,n,0); dp[0]=node2(0,0);
	for (i=1;i<=n;i++){
		if (i>a[l].r) l++;
		dp[i]=work(a[l].thi,i);
		while ((i+1<=a[r].l)&&(work(i,a[r].l)<work(a[r].thi,a[r].l))){
			a[r]=node(0,0,0); r--;
		}
		ans=a[r].l; ll=a[r].l; rr=a[r].r;
		while (ll<=rr){
			mid=(ll+rr)>>1;
			if ((i>mid)||(work(a[r].thi,mid)<=work(i,mid))){
				ans=mid; ll=mid+1;
			}
			else rr=mid-1;
		}
		if (ans!=n){
			a[r].r=ans;
			r++; a[r].l=ans+1; a[r].r=n; a[r].thi=i;
		}
	}
	return dp[n].y;
}
int main(){
	n=read(); m=read();
	for (i=1;i<=n;i++){
		for (j=1;j<=n;j++){
			mp[i][j]=read()+mp[i][j-1]+mp[i-1][j]-mp[i-1][j-1];
		}
	}
	l=-1; r=1e9;
	while (l<=r){
		mid=(l+r)>>1;
		if (check()<=m){
			r=mid-1; ans=mid; anss=dp[n].x-m*ans;
		}
		else l=mid+1;
	}
	printf("%d\n",anss);
	return 0;
}