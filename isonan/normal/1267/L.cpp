#include <cstdio>

int n,l,k;
int cnt[26],mx,mn,pos[1001];
char str[1000001];
char ans[1001][1001];
bool comp[1001];
char big(){
	while(!cnt[mx])--mx;
	--cnt[mx];
	return mx+'a';
}
char small(){
	while(!cnt[mn])++mn;
	--cnt[mn];
	return mn+'a';
}
int main(){
	scanf("%d%d%d",&n,&l,&k);
	scanf("%s",str+1);
	for(int i=1;i<=n*l;i++)++cnt[str[i]-'a'];
	mx=25;mn=0;
	for(int i=1;i<=n;i++)pos[i]=l+1;
	for(int i=1;i<=l;i++){
		for(int m=1;m<=n;m++)
			if(!comp[m])
				if(m<=k)ans[m][i]=small();
		for(int m=n;m;m--)
			if(!comp[m])
				if(m>k)ans[m][i]=big();
		for(int m=1;m<=n;m++)if(!comp[m]&&ans[m][i]!=ans[k][i])comp[m]=1,pos[m]=i+1;
	}
	for(int i=1;i<=n;i++)
		for(int j=pos[i];j<=l;j++)
			ans[i][j]=small();
	for(int i=1;i<=n;i++,putchar('\n'))
		for(int j=1;j<=l;j++)putchar(ans[i][j]);
}