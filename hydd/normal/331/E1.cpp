/*********************************************************************
 * Source2
 * ProblempathCF331E1/E2
 * Authorhydd
 * Date2020/10/18
*********************************************************************/
#include<cstdio>
#include<utility>
#include<vector>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
const int Mod=1e9+7;
int n,m,num[110][110],v[110];
int top,s[21000],top2,s2[21000];
int ans,Ans[21000];
vector<int> vec[21000];
struct node{
	int x,y,k;
} a[21000];
char Getchar(){
	static char now[1<<20],*S,*T;
	if (T==S){
		T=(S=now)+fread(now,1,1<<20,stdin);
		if (T==S) return EOF;
	}
	return *S++;
}
int read(){
	int x=0,f=1;
	char ch=Getchar();
	while (ch<'0'||ch>'9'){
		if (ch=='-') f=-1;
		ch=Getchar();
	}
	while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=Getchar();
	return x*f;
}
pii get_path(int x,bool rev){///
	int now=0,y,e;
	for (int i=1;i<=top&&top<=2*n;i++){
		y=s[i]; e=num[x][y];
		if (!e||(rev&&e<=m)||(!rev&&e>m)) return pii(2*n+1,2*n+1);
		for (int j=0;j<(int)vec[e].size();j++) s[++top]=vec[e][j];
		x=y; now++;
	}
	return pii(top,x);
}
int dp1[2][2][55][55][110],dp2[110][55][2];
int f[55][55][110],g[55][55][110];
void work(bool rev){//
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for (int i=1;i<=m*2;i++){
		if ((rev&&i<=m)||(!rev&&i>m)) continue;
		for (int j=0;j<(int)vec[i].size();j++)
			if (vec[i][j]==a[i].x){
				top=0; for (int k=j-1;k>=0;k--) s[++top]=vec[i][k];
				pii res=get_path(a[i].x,!rev);
				if (res.first+1>2*n) continue;
				if (j+1==(int)vec[i].size())
					g[res.second][a[i].y][res.first+1]++;//
				else{
					if (vec[i][j+1]!=a[i].y) continue;
					top2=0;
					for (int i=top;i>=1;i--) s2[++top2]=s[i];
					top=0; for (int k=j+2;k<(int)vec[i].size();k++) s[++top]=vec[i][k];
					pii res2=get_path(a[i].y,rev);
					
					if (res2.first+1+res.first>2*n) continue;
					if (!ans){
						for (int i=1;i<=top2;i++) Ans[++ans]=s2[i];
						Ans[++ans]=a[i].x; Ans[++ans]=a[i].y;
						for (int i=1;i<=top;i++) Ans[++ans]=s[i];
					}
					f[res.second][res2.second][res2.first+1+res.first]++;//
				}
			}
	}
}
int main(){
	scanf("%d%d",&n,&m); int x,y,k;
	for (int i=1;i<=m;i++){
		x=read(); y=read(); k=read();
		for (int j=1;j<=k;j++) v[j]=read();
		
		a[i].x=x; a[i].y=y; a[i].k=k;
		num[x][y]=i;
		for (int j=1;j<=k;j++) vec[i].push_back(v[j]);
		
		a[i+m].x=y; a[i+m].y=x; a[i+m].k=k;
		num[y][x]=i+m;
		for (int j=1;j<=k;j++) vec[i+m].push_back(v[k-j+1]);
		
		if (!k) dp1[0][0][x][y][1]++;
	}
	work(false);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n*2;k++){
				dp1[1][1][i][j][k]=f[i][j][k];
				dp1[1][0][i][j][k]=g[i][j][k];
			}
	if (ans){
		printf("%d\n",ans);
		for (int i=1;i<ans;i++) printf("%d ",Ans[i]);
		printf("%d\n",Ans[ans]);
	} else puts("0\n");
	/*work(true);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n*2;k++)
				dp1[0][1][i][j][k]=g[j][i][k];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n*2;k++){
				dp2[k][j][0]=(dp2[k][j][0]+dp1[1][0][i][j][k])%Mod;
				dp2[k][j][1]=(dp2[k][j][1]+dp1[1][1][i][j][k])%Mod;
			}
	for (int p=1;p<=n*2;p++){
		int res=0;
		for (int i=1;i<=n;i++){
			res=(res+dp2[p][i][1])%Mod;
			for (int m=0;m<=1;m++)
				if (dp2[p][i][m]){
					for (int s=0;s<=1;s++)
						for (int x=1;x<=n;x++)
							for (int q=1;q<=n*2-p;q++)
								dp2[p+q][x][s]=(dp2[p+q][x][s]+1ll*dp2[p][i][m]*dp1[m^1][s][i][x][q])%Mod;
				}
		}
		printf("%d\n",res);
	}*/
	return 0;
}