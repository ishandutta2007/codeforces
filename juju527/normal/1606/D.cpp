#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
vector<vector<int>> a;
multiset<int>l[maxn],r[maxn];
struct node{
	int id,mn,mx;
	bool operator <(node i)const{return mn<i.mn;}
}p[maxn],q[maxn];
int pos[maxn];
int premx[maxn];
int vis[maxn];
int main(){
	int T;
	T=read();
	while(T--){
		int n,m;
		n=read();m=read();
		vector<vector<int>>().swap(a);
		a.resize(n+1);
		for(int i=1;i<=n;i++){
			a[i].resize(m+1);
			for(int j=1;j<=m;j++)a[i][j]=read();
		}
		for(int i=1;i<=n;i++){
			l[i].clear();r[i].clear();
			for(int j=1;j<=m;j++)r[i].insert(a[i][j]);
		}
		int res=0;
		for(int k=1;k<m;k++){
			for(int i=1;i<=n;i++)vis[i]=0;
			for(int i=1;i<=n;i++){
				l[i].insert(a[i][k]),r[i].erase(r[i].find(a[i][k]));
				p[i]=(node){i,*l[i].begin(),*l[i].rbegin()};q[i]=(node){i,*r[i].begin(),*r[i].rbegin()};
			}
			sort(p+1,p+n+1);sort(q+1,q+n+1);
			for(int i=1;i<=n;i++)pos[p[i].id]=i;
			bool flag=1;
			int pre=0,Pos;
			for(int i=1;i<n;i++){
				pre=max(pre,p[i].mx);premx[i]=max(premx[i-1],q[i].mx);
				if(pre<p[i+1].mn)vis[i]=1;
			}
			pre=0;
			for(int i=n;i>1;i--){
				pre=max(pre,pos[q[i].id]);
				if(pre==n-i+1&&q[i].mn>premx[i-1]&&vis[n-i+1]){flag=0;Pos=n-i+1;break;}
			}
			if(flag)continue;
			for(int i=1;i<=Pos;i++)vis[p[i].id]=0;
			for(int i=Pos+1;i<=n;i++)vis[p[i].id]=1;
			res=k;
			break;
		}
		if(!res)puts("NO");
		else{
			puts("YES");
			for(int i=1;i<=n;i++)if(vis[i]==1)putchar('R');else putchar('B');
			printf(" %d\n",res);
		}
	}
    return 0;
}