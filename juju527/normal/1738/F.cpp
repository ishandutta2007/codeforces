//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=1005;
pii d[maxn];
int c[maxn];
int f[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int query(int x){
	printf("? %d\n",x);fflush(stdout);
	return read();
}
int find(int x){return (x==f[x])?x:f[x]=find(f[x]);}
int main(){
    int T;
	T=read();
	while(T--){
		int n;
		n=read();
		for(int i=1;i<=n;i++)d[i]=pii(read(),i),c[i]=0,f[i]=i;
		sort(d+1,d+n+1);
		for(int i=n;i>=1;i--){
			int x=d[i].se;
			if(c[x])continue;
			c[x]=1;
			for(int j=1;j<=d[i].fi;j++){
				int y=query(x);
				if(c[y]){f[find(x)]=find(y);break;}
				c[y]=1;f[find(x)]=find(y);
			}
		}
		printf("! ");
		for(int i=1;i<=n;i++)printf("%d ",find(i));
		puts("");fflush(stdout);
	}
    return 0;
}