#include <cstdio>

int n,q;
char str[100001];
bool vis[100001];
bool check(int x){
	if(x<1||x+2>n)return 0;
	if(str[x]=='a'&&str[x+1]=='b'&&str[x+2]=='c')return 1;
	return 0;
}
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",str+1);
	int ans=0;
	for(int i=1;i<=n;++i)if(check(i))++ans;
	for(int i=1;i<=q;++i){
		int p;
		scanf("%d",&p);
		char ch=getchar();
		while(ch<'a'||ch>'c')ch=getchar();
		if(check(p-2))--ans;
		if(check(p-1))--ans;
		if(check(p-0))--ans;
		str[p]=ch;
		if(check(p-2))++ans;
		if(check(p-1))++ans;
		if(check(p-0))++ans;
		printf("%d\n",ans);
	}
}