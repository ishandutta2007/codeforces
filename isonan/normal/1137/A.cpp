#include <map>
#include <cstdio>
#include <algorithm>

int str[2001],map[2001][2001],n,m,ansr[1001],ansc[1001];
std::map<int,int>row[1001],col[1001];
int exir[1001][1001],exic[1001][1001];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&map[i][j]);
			++row[i][map[i][j]];
			++col[j][map[i][j]];
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)str[j]=map[i][j];
		std::sort(str+1,str+m+1);
		ansr[i]=std::unique(str+1,str+m+1)-str-1;
		for(int j=1;j<=m;j++)exir[i][j]=std::lower_bound(str+1,str+ansr[i]+1,map[i][j])-str;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++)str[j]=map[j][i];
		std::sort(str+1,str+n+1);
		ansc[i]=std::unique(str+1,str+n+1)-str-1;
		for(int j=1;j<=n;j++)exic[j][i]=std::lower_bound(str+1,str+ansc[i]+1,map[j][i])-str;
	}
	for(int i=1;i<=n;i++,putchar('\n'))
		for(int j=1;j<=m;j++){
			int tem=std::max(exir[i][j],exic[i][j]);
			printf("%d ",std::max(ansr[i]-exir[i][j]+tem,ansc[j]-exic[i][j]+tem));
		}
}