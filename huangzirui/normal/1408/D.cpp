#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=2010;
int i,j,k,n,m,T;
struct node{
	int x,y;
}a[maxn],b[maxn];
struct edge{
	int up,right;
}E[maxn*maxn];
bool cmp(edge x,edge y){
	return x.up>y.up || (x.up==y.up && x.right>y.right);
}
int cnt,cnt2=1;
int ans=2e9;
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++)a[i]={read(),read()};
	for(i=1;i<=m;i++)b[i]={read(),read()};
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			E[++cnt]={max(0,b[j].x-a[i].x+1),max(0,b[j].y-a[i].y+1)};
	sort(E+1,E+1+cnt,cmp);
	for(i=2;i<=cnt;i++)
		if(E[i].right>E[cnt2].right)E[++cnt2]=E[i];
	E[0].up=1e9;E[cnt2+1].right=1e9;
	if(cnt2==1)ans=min(E[1].up,E[1].right);
	else for(i=0;i<=cnt2;i++)ans=min(ans,E[i].right+E[i+1].up);
	cout<<ans<<endl;
	return 0;
}