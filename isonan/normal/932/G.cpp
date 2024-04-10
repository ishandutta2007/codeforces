#include <cstdio>
#include <cstring>

const int P=1000000007;
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int n,s[1000001],son[1000001][26],fail[1000001],cnt=1,last=1,len[1000001],pos[1000001],f[1000001],dif[1000001],an[1000001],g[1000001];
char tem[1000001];
int get_fail(int x){while(s[n-len[x]-1]!=s[n])x=fail[x];return x;}
void add(int x){
	s[++n]=x;
	int p=get_fail(last);
	if(!son[p][x]){
		len[++cnt]=len[p]+2;
		fail[cnt]=son[get_fail(fail[p])][x];
		son[p][x]=cnt;
		dif[cnt]=len[cnt]-len[fail[cnt]];
		an[cnt]=(dif[cnt]==dif[fail[cnt]])?an[fail[cnt]]:fail[cnt];
	}
	last=son[p][x];
}
int main(){
	scanf("%s",tem+1);
	int nl=strlen(tem+1);
	len[1]=s[0]=-1;
	fail[0]=1;
	f[0]=1;
	for(int i=1;i<=nl;i++){
		add(tem[i%2==1?(i+1)>>1:(nl-(i>>1)+1)]-'a');
//		for(int j=last;j;j=fail[j])printf("%d ",len[j]);putchar('\n');
//		for(int j=last;j;j=fail[j])f[i]=add(f[i],f[i-len[j]]);
		for(int j=last;j;j=an[j]){
//			printf("%d %d\n",j,len[j]);
//			printf("*%d %d %d %d %d\n",j,fail[j],an[j],dif[j],i-len[an[j]]-dif[j]);
			int tem=0;
//			for(int k=fail[j];k!=an[j];k=fail[k])tem=add(tem,f[i-len[k]]),printf("%d\n",i-len[k]);
			g[j]=add((an[j]==fail[j])?0:g[fail[j]],f[i-len[an[j]]-dif[j]]);
//			printf("%d %d %d\n",g[j],tem,f[i-len[an[j]]-dif[j]]);
			f[i]=add(f[i],g[j]);
		}
		if(i%2)f[i]=0;
//		printf("*%d %d\n",i,f[i]);
	}
//	for(int i=0;i<=cnt;i++){
//		printf("%d : %d %d ",i,len[i],dif[i]);
//		for(int j=0;j<26;j++)
//			if(son[i][j])printf("(%d %c)",son[i][j],j+'a');
//		putchar('\n');
//	}
	printf("%d\n",f[nl]);
}