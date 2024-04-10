#include<cstdio>
using namespace std;
int n,m,a[110000],b[2][110000],fa[210000];
int findset(int x){
	if (fa[x]!=x) fa[x]=findset(fa[x]);
	return fa[x];
}
void Union(int x,int y){
	x=findset(x); y=findset(y);
	if (x!=y) fa[y]=x;
}

int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    int x,y;
    for (int i=1;i<=m;i++){
        scanf("%d",&x);
        while (x--){
            scanf("%d",&y);
            if (b[0][y]) b[1][y]=i;
            else b[0][y]=i;
        }
    }
	for (int i=1;i<=m+m;i++) fa[i]=i;
	for (int i=1;i<=n;i++){
        if (!a[i]) Union(b[0][i],b[1][i]+m),Union(b[1][i],b[0][i]+m);
        else Union(b[0][i],b[1][i]),Union(b[0][i]+m,b[1][i]+m);
    }
	for (int i=1;i<=m;i++)
		if (findset(i)==findset(i+m)){
			puts("NO");
			return 0;
		}
    puts("YES");
	return 0;
}