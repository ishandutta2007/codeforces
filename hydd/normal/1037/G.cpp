/*********************************************************************
 * SourceCodeforces
 * ProblemCF1037G
 * Authorhydd
 * Date2020/11/9
*********************************************************************/
#include<cstdio>
#include<cstring>
using namespace std;
char s[110000]; int n,q,l,r;
int nxt[110000][26],lst[110000][26],num[27];
int f[110000][26],g[110000],pos[26];
int calc(int x){
	int res=0;
	while (x&1) x>>=1,res++;
	return res;
}
int calc1(int l,int r,int lc){//r=nxt[l][lc]-1
	if (l>r) return 0;
	if (num[lc]!=-1) return num[lc];
	int res=0,tmp;
	for (int c=0;c<26;c++){
		int x=nxt[l][c],y=lst[r][c];
		if (x<=y){
			tmp=calc1(l,x-1,c)^(g[x]^g[y])^f[y+1][lc];
			if (tmp<26) res|=1<<tmp;
		}
	}
	num[lc]=calc(res);
	return num[lc];
}
int calc2(int l,int r,int lc){//l=lst[r][lc]+1lc!=26
	if (l>r) return 0;
	if (num[lc]!=-1) return num[lc];
	int res=0,tmp;
	for (int c=0;c<26;c++){
		int x=nxt[l][c],y=lst[r][c];
		if (x<=y){
			tmp=f[l][c]^(g[x]^g[y])^calc2(y+1,r,c);
			if (tmp<26) res|=1<<tmp;
		}
	}
	num[lc]=calc(res);
	return num[lc];
}

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for (int i=1;i<=n;i++) s[i]-='a';
	
	for (int c=0;c<26;c++) pos[c]=0;
	for (int i=1;i<=n;i++){
		pos[s[i]]=i;
		for (int c=0;c<26;c++) lst[i][c]=pos[c];
	}
	
	for (int c=0;c<26;c++) pos[c]=n+1;
	for (int i=n;i>=1;i--){
		pos[s[i]]=i;
		for (int c=0;c<26;c++) nxt[i][c]=pos[c];
	}
	
	
	for (int i=n;i>=1;i--){
		int j=nxt[i+1][s[i]];
		g[i]=f[i+1][s[i]]^g[j];//i..n s[i]sg
		for (int c=0;c<26;c++) num[c]=-1;
		for (int c=0;c<26;c++) f[i][c]=calc1(i,nxt[i][c]-1,c);
	}
	
	scanf("%d",&q); int l,r;
	while (q--){
		scanf("%d%d",&l,&r);
		for (int c=0;c<=26;c++) num[c]=-1;
		if (calc2(l,r,26)) puts("Alice");
		else puts("Bob");
	}
	return 0;
}