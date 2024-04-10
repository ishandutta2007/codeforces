// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k;
int T,opt;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int n;
char c=' ';
int s[maxn],a[maxn],b[maxn];
int len;
int ha[32],fla,haa[32];
void check(){
	int i;
	for (i=1;i<=len;i++){
		if (ha[s[i]]<b[i]){
			fla=1; return;
		}
		if (ha[s[i]]>b[i]){
			fla=-1; return;
		}
	}
	fla=1;
}
void work(int x,int thi){
	if (fla!=0) return;
	int i;
	if (x>len){
		check();
		return;
	}
	if (ha[s[x]]==0){
		for (i=1;i<=n;i++){
			if (haa[i]==0){
				ha[s[x]]=i; haa[i]=1;
				if (ha[s[x]]>a[x]) work(x+1,1);
				if (ha[s[x]]==a[x]) work(x+1,thi);
				if (ha[s[x]]<a[x]){
					if (thi==1){
						work(x+1,thi);
					}
				}
				if (fla!=0) return;
				ha[s[x]]=0; haa[i]=0;
			}
		}
	}
	else{
		if (ha[s[x]]>a[x]){
			work(x+1,1);
		}
		if (ha[s[x]]==a[x]){
			work(x+1,thi);
		}
		if (ha[s[x]]<a[x]){
			if (thi==0) return;
			else work(x+1,thi);
		}
	}
}
int main(){
	T=read();
	for (opt=1;opt<=T;opt++){
		n=read();
		while ((c<'a')||(c>'z')) c=getchar();
		len=0;
		memset(ha,0,sizeof(ha)); fla=0;
		memset(haa,0,sizeof(haa));
		while ((c>='a')&&(c<='z')){
			len++; s[len]=c-'a'+1;
			c=getchar();
		}
		len=0;
		while ((c<'a')||(c>'z')) c=getchar();
		while ((c>='a')&&(c<='z')){
			len++; a[len]=c-'a'+1;
			c=getchar();
		}
		len=0;
		while ((c<'a')||(c>'z')) c=getchar();
		while ((c>='a')&&(c<='z')){
			len++; b[len]=c-'a'+1;
			c=getchar();
		}
		work(1,0);
		if (fla==1){
			printf("YES\n");
			j=1;
			for (i=1;i<=n;i++){
				if (ha[i]==0){
					while (haa[j]!=0) j++;
					ha[i]=j; j++;
				}
			}
			for (i=1;i<=n;i++){
				printf("%c",ha[i]+'a'-1);
			}
			printf("\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}