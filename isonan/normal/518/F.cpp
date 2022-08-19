#include <cstdio>
#include <cstring>

int n,m,cnt[4];
bool map[2001][2001],con[2010][2010][4];
long long ans;
bool get(){
	char ch=getchar();
	while(ch!='.'&&ch!='#')ch=getchar();
	return (ch=='.');
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			map[i][j]=get();
	for(int i=1;i<=n;i++)con[i][0][0]=1;
	for(int i=1;i<=m;i++)con[0][i][1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			con[i][j][0]=con[i][j-1][0]&map[i][j],
			con[i][j][1]=con[i-1][j][1]&map[i][j];
	for(int i=1;i<=n;i++)con[i][m+1][2]=1;
	for(int i=1;i<=m;i++)con[n+1][i][3]=1;
	for(int i=n;i;i--)
		for(int j=m;j;j--)
			con[i][j][2]=con[i][j+1][2]&map[i][j],
			con[i][j][3]=con[i+1][j][3]&map[i][j];
	for(int i=2;i<n;i++)
		for(int j=2;j<m;j++){
			bool *c=con[i][j];
			ans+=(c[0]&&c[1])+(c[0]&&c[3])+(c[2]&&c[1])+(c[2]&&c[3]);
		}
	for(int i=2;i<n;i++){
		memset(cnt,0,sizeof cnt);
		for(int j=2;j<m;j++){
			bool *c=con[i][j];
			if(!map[i][j])memset(cnt,0,sizeof cnt);
			int v=cnt[3]+cnt[1];
			ans+=(c[1]+c[3])*v;
			if(j>2)ans-=(c[1]&&con[i][j-1][1])+(c[3]&&con[i][j-1][3]);
			if(map[i][j])for(int k=0;k<4;k++)cnt[k]+=c[k];
		}
	}
	for(int j=2;j<m;j++){
		memset(cnt,0,sizeof cnt);
		for(int i=2;i<n;i++){
			bool *c=con[i][j];
			if(!map[i][j])memset(cnt,0,sizeof cnt);
			int v=cnt[0]+cnt[2];
			ans+=(c[0]+c[2])*v;
			if(i>2)ans-=(c[0]&&con[i-1][j][0])+(c[2]&&con[i-1][j][2]);
			if(map[i][j])for(int k=0;k<4;k++)cnt[k]+=c[k];
		}
	}
	for(int i=2;i<n;i++)ans+=con[i][m][0];
	for(int i=2;i<m;i++)ans+=con[n][i][1];
	printf("%lld\n",ans);
}