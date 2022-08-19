#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <set>

std::set<int>V,C;
int head[100001],nxt[2000001],b[2000001],k,con[1000001][2],t;
void push(int s,int t,bool bb=1){
	nxt[++k]=head[s];
	head[s]=k;
	b[k]=t;
	if(bb)++::t,con[::t][0]=s,con[::t][1]=t;
}
int n,m,siz,stat[201];
char str[21],Now[21];
bool cando,col[21];
char get(){
	char ch=getchar();
	while(ch!='V'&&ch!='C')ch=getchar();
	return ch;
}
int rev(int x){return x<=n?x+n:x-n;}
#define wrong(){puts("-1");return 0;}
int low[100001],dfn[100001],now,stk[100001],top,S,ans[100001];
bool instack[100001],vis[100001];
void tarjan(int x){
	low[x]=dfn[x]=++now;
	instack[x]=1;
	stk[++top]=x;
	for(int i=head[x];i;i=nxt[i])
		if(!dfn[b[i]])tarjan(b[i]),low[x]=std::min(low[x],low[b[i]]);
		else if(instack[b[i]])low[x]=std::min(low[x],dfn[b[i]]);
	if(low[x]==dfn[x]){
		++S;
		do{
			ans[stk[top]]=S;
			instack[stk[top]]=0;
			--top; 
		}while(stk[top+1]!=x);
	}
}
bool check(int pre){
	memset(vis,0,sizeof vis);
	for(int i=1;i<=pre;i++)
		vis[ans[i+col[Now[i]]*n]]=1;
	for(int i=S;i;i--)
		if(vis[i])
			for(int j=head[i];j;j=nxt[j])
				vis[b[j]]=1;
	for(int i=1;i<=n;i++)
		if(vis[ans[i]]&&vis[ans[i+n]])return 0;
	return 1;
}
int main(){
	scanf("%s%d%d",str,&n,&m);
	siz=strlen(str);
	for(int i=0;i<siz;i++)
		if(str[i]=='V')V.insert(i);
		else col[i]=1, C.insert(i);
	V.insert(siz);
	C.insert(siz);
	for(int i=1,pos1,t1,pos2,t2;i<=m;i++){
		scanf("%d",&pos1),pos1+=(get()=='C')*n;
		scanf("%d",&pos2),pos2+=(get()=='C')*n;
		push(pos1,pos2);
		push(rev(pos2),rev(pos1));
	}
	for(int i=1;i<=(n<<1);i++)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;i++)
		if(ans[i]==ans[i+n])wrong();
	memset(head,0,sizeof head);
	k=0;
	for(int i=1;i<=t;i++)
		if(ans[con[i][0]]!=ans[con[i][1]])
			push(ans[con[i][0]],ans[con[i][1]],0);
	scanf("%s",Now+1);
	for(int i=1;i<=n;i++)Now[i]-='a';
	if(check(n)){for(int i=1;i<=n;i++)putchar(Now[i]+'a');return 0;}
	int p=0,mncando=0;
	for(int i=n,pV,pC,orig;i;i--){
		pV=*V.upper_bound(Now[i]),pC=*C.upper_bound(Now[i]),orig=Now[i];
		if(pV==siz&&pC==siz)continue;
		Now[i]=std::min(pV,pC);
		if(check(i)){p=i;break;}
		else{
			if(std::max(pV,pC)<siz){
				Now[i]=std::max(pV,pC);
				if(check(i)){
					p=i;
					break;
				}
			}
		}
		Now[i]=orig;
	}
	if(!p)wrong();
	for(int i=p+1,pV,pC;i<=n;i++){
		pV=*V.begin(),pC=*C.begin();
		Now[i]=std::min(pV,pC);
		if(!check(i)){
			if(std::max(pV,pC)==siz)wrong();
			Now[i]=std::max(pV,pC);
		}
	}
	if(!check(n))wrong();
	for(int i=1;i<=n;i++)putchar(Now[i]+'a');
}