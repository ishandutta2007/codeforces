#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))

int i,j,k,n,m,t,id[10050],res[100500],a[13][100500],op,g[100500],it,it2,x,y,p[66],sb[66];
bitset<4100> f[100050];
vector<pair<int,int> >qu[100500];

bool cmp(int x,int y){
	return sb[x]<sb[y];
}

#define getchar()(p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline ll rd()
{
    char c=getchar();ll x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

int main() {
	for(i=1;i<=12;i++)id[b(i)]=i;
	//cin.tie(0);
	m=rd();n=rd();t=rd();
	it=n;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)a[i][j]=rd();
	}
	for(i=0;i<b(n+1);i++){
		for(j=1;j<=n;j++){
			if(b(j)&i)f[j][i]=1;
		}
	}
	for(i=1;i<=t;i++){
		op=rd();x=rd();y=rd();
		if(op==1||op==2){
			g[++it]=op;
			if(op==2)f[it]=f[x]&f[y];
			else f[it]=f[x]|f[y];
		}
		else{
			qu[y].push_back({++it2,x});
		}
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			p[j]=j;sb[j]=a[j][i];
		}
		sort(p+1,p+n+1,cmp);
		int msk;
		for(auto [id1,x]:qu[i]){
			msk=0;
			for(j=n;j>=1;j--){
				msk|=b(p[j]);
				if(f[x][msk]==1){
					res[id1]=a[p[j]][i];
					break;
				}
			}
		}
	}
	for(i=1;i<=it2;i++)printf("%d\n",res[i]);
}