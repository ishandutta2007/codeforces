#include <cstdio>
#include <vector>
#include <cstring>

int len[1000010],son[1000010][26],nxt[1000010],cnt=1,last,n,pre[1000010],pos[1000010],fa[1000010],diff[1000010],faz[1000010];
int an[1000010];
char str1[1000010],str2[1000010],s[1000010];
std::vector<int>ans;
int getnxt(int x){
	while(s[n]!=s[n-len[x]-1])x=nxt[x];//,printf("-%d %d %d\n",n,x,len[x]);
	return x;
}
void add(int x){
	++n;
	int cur=getnxt(last);
	if(!son[cur][x]){
		len[++cnt]=len[cur]+2;
		nxt[cnt]=son[getnxt(nxt[cur])][x];
		son[cur][x]=cnt;
		diff[cnt]=len[cnt]-len[nxt[cnt]];
		an[cnt]=(diff[cnt]==diff[nxt[cnt]])?an[nxt[cnt]]:nxt[cnt];
	}
	last=son[cur][x];
}
struct info{
	int v,p;
}f[1000010],g[1000010];
void upd(info &a,info b){
	if(a.v>b.v)a=b;
}
int main(){
	scanf("%s%s",str1+1,str2+1);
	int len=strlen(str1+1);
	for(int i=1;i<=len;i++)s[(i<<1)-1]=str1[i],s[i<<1]=str2[i];
	len<<=1;
//	for(int i=1;i<=len;i++)printf("%c",s[i]);putchar('\n');
	nxt[0]=1,::len[1]=-1;
	s[0]=-1;
	for(int i=1;i<=len;i++)f[i].v=0x7f7f7f7f;
	for(int i=0;i<=cnt;i++)g[i].v=0x7f7f7f7f;
	f[0].v=0;
	for(int i=1;i<=len;i++){
		add(s[i]-'a');
		if(s[i]==s[i-1]&&i>1)upd(f[i],(info){f[i-2].v,2});
//		printf("%d %d\n",i,::len[last]);
		for(int j=last;j;j=an[j]){
			g[j].v=0x7f7f7f7f;
			if(an[j]!=nxt[j])upd(g[j],(info){g[nxt[j]].v,g[nxt[j]].p+diff[j]});
//			printf("%d %d %d\n",i,j,::len[an[j]]+diff[j]);
			upd(g[j],(info){f[i-::len[an[j]]-diff[j]].v+1,::len[an[j]]+diff[j]});
			upd(f[i],g[j]);
		}
		if(i%2)f[i].v=0x7f7f7f7f;
//		printf("%d %d\n",i,f[i].v);
	}
	if(f[len].v>len)puts("-1");
	else{
		int tem=len;
		while(tem){
			if(f[tem].p>2)ans.push_back(tem);
			tem-=f[tem].p;
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)printf("%d %d\n",((ans[i]-f[ans[i]].p)>>1)+1,(ans[i]>>1));
	}
}