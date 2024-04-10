#include <cstdio>
#include <cstring>
#include <algorithm>

int t;
int n;
int f[52][1024],pre[52][1024][2];
int pos[11][52][2];
int stk[1001],top;
int get(char ch){
	if(ch>='a'&&ch<='z')return ch-'a';
	else return ch-'A'+26;
}
void upd(int a,int b,int c,int d){
	if(f[a][b]<f[c][d]+1){
		f[a][b]=f[c][d]+1;
		pre[a][b][0]=c;
		pre[a][b][1]=d;
	}
}
char trans(int x){
	if(x<26)return x+'a';
	else return x-26+'A';
}
char str[1001];
std::pair<int,int>num[100001];
bool cmp(std::pair<int,int> a,std::pair<int,int>b){
	for(int i=0;i<n;++i)
		if(pos[i][a.first][((a.second&(1<<i))!=0)]<pos[i][b.first][((b.second&(1<<i))!=0)])return 0;
		else if(pos[i][a.first][((a.second&(1<<i))!=0)]>pos[i][b.first][((b.second&(1<<i))!=0)])return 1;
	return 0;
}
bool ok(int i,int j){
	for(int l=0;l<n;++l)
		if(!pos[l][i][((j&(1<<l))!=0)])return 0;
	return 1;
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		memset(pos,0,sizeof pos);
		for(int i=0;i<n;++i){
			scanf("%s",str+1);
			int l=strlen(str+1);
			for(int j=1;j<=l;++j){
				int x=get(str[j]);
				if(pos[i][x][0])pos[i][x][1]=j;
				else pos[i][x][0]=j;
			}
		}
		memset(f,-0x3f,sizeof f);

		int cnt=0;
		for(int i=0;i<52;++i)
			for(int j=0;j<(1<<n);++j)
				if(ok(i,j)){
					f[i][j]=0;
					num[++cnt]=std::make_pair(i,j);
					// printf("%c %d\n",trans(i),j);
				}
		std::sort(num+1,num+cnt+1,cmp);
		for(int u=cnt;u;--u){
			int i=num[u].first,j=num[u].second;
			// printf("%c %d %d\n",trans(i),j,f[i][j]);
				for(int k=0;k<52;++k){
					int stat=0;
					bool ok=1;
					for(int l=0;l<n;++l)
						if(pos[l][k][0]&&pos[l][k][0]>pos[l][i][((j&(1<<l))!=0)]);
						else if(pos[l][k][1]&&pos[l][k][1]>pos[l][i][((j&(1<<l))!=0)])stat|=1<<l;
						else ok=0;
					if(ok)upd(k,stat,i,j);
				}
		}
		int p1=0,p2=0;
		for(int i=0;i<52;++i)
			for(int j=0;j<(1<<n);++j)
				if(f[i][j]>f[p1][p2])p1=i,p2=j;
		if(f[p1][p2]<0){
			puts("0");
			putchar('\n');
			continue;
		}
		top=0;
		for(;;){
			stk[++top]=p1;
			if(!f[p1][p2])break;
			int tem=pre[p1][p2][0],tem2=pre[p1][p2][1];
			p1=tem;
			p2=tem2;
		}
		printf("%d\n",top);
		for(int i=top;i;--i)putchar(trans(stk[i]));putchar('\n');
	}
}