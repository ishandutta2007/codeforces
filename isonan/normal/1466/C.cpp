#include <cstdio>
#include <algorithm>
#include <cstring>

int t;
struct info{
	int mn,skdmn,pos,skdpos;
	void add(int x,int y){
		if(x<mn){
			skdmn=mn;
			skdpos=pos;
			mn=x;
			pos=y;
		}
		else if(x<skdmn)skdmn=x,skdpos=y;
	}
}f[100001][26];
char s[100001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int j=0;j<26;j++)
			f[1][j]=(info){(j!=s[1]-'a'),(j!=s[1]-'a'),-1};
		for(int i=2;i<=n;i++){
			for(int j=0;j<26;j++){
				f[i][j]=(info){0x7f7f7f7f,0x7f7f7f7f,-1};
				for(int k=0;k<26;k++)
					if(j!=k){
						if(f[i-1][k].pos!=j)f[i][j].add(f[i-1][k].mn,k);
						else f[i][j].add(f[i-1][k].skdmn,k);
					}
				f[i][j].mn+=(j!=s[i]-'a');
				f[i][j].skdmn+=(j!=s[i]-'a');
//				printf("%d %d %d\n",i,j,f[i][j].pos);
			}
		}
		int ans=0x7f7f7f7f;
		for(int i=0;i<26;i++)ans=std::min(ans,f[n][i].mn);
		printf("%d\n",ans);
	}
}