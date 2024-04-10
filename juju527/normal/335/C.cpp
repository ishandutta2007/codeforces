#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
struct node{
	int u,v;
	bool operator <(node i)const{
		return u<i.u;
	}
}a[maxn];
int l[maxn];
int f[maxn][3][3];
int vis[maxn][3][3];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
//    freopen("CF335C.in","r",stdin);
//    freopen("CF335C.out","w",stdout);
    int r,n;
	r=read();n=read();
	for(int i=1;i<=n;i++){
		int u,v;
		u=read();v=read()-1;
		a[i].u=u;a[i].v=v;
		l[u]|=(1<<v);
		if(l[u]==3){puts("LOSE");return 0;}
	}
	for(int i=1;i<=r;i++){
		memset(vis,0,sizeof(vis));
		for(int s=0;s<=2;s++)
			for(int t=0;t<=2;t++)
				for(int j=0;j<i;j++)
					for(int k=1;k<=2;k++){
						if((j==0&&k!=s&&s)||(j==i-1&&k!=t&&t))continue;
//						cout<<"qaq\n";
						vis[f[j][s][k]^f[i-j-1][k][t]][s][t]=1;
					}
		for(int s=0;s<=2;s++){
			for(int t=0;t<=2;t++){
				int p=0;
				for(int j=0;j<=i;j++)if(!vis[j][s][t]){p=j;break;}
				f[i][s][t]=p;
//				cout<<i<<" "<<s<<" "<<t<<" "<<f[i][s][t]<<endl;
			}
		}
	}
	sort(a+1,a+n+1);
	a[0].u=0;
	a[n+1].u=r+1;
	int ans=0;
	for(int i=1;i<=n+1;i++)
		ans^=f[a[i].u-a[i-1].u-1][l[a[i-1].u]][l[a[i].u]];
//	cout<<a[n+1].u<<" "<<a[n].u<<endl;
//	cout<<ans<<endl;
	if(ans>0)puts("WIN");
	else puts("LOSE");
    return 0;
}