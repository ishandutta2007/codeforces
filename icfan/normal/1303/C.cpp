#include <cstdio>
#include <cstring>
const int Maxn=200;
int t;
char s[Maxn+5];
int n;
int lnk[30][2];
bool co[30][30];
bool vis[30];
int main(){
	scanf("%d",&t);
	bool flag;
	while(t--){
		scanf("%s",s+1);
		n=0;
		while(s[++n]!='\0');
		n--;
		flag=1;
		memset(co,0,sizeof co);
		memset(lnk,-1,sizeof lnk);
		memset(vis,0,sizeof vis);
		for(int i=2;i<=n;i++){
			if(co[s[i-1]-'a'][s[i]-'a']){
				continue;
			}
			if(lnk[s[i-1]-'a'][0]==-1&&lnk[s[i]-'a'][1]==-1){
				int j=s[i-1]-'a';
				while(j!=-1){
					if(j==s[i]-'a'){
						break;
					}
					j=lnk[j][1];
				}
				if(j==-1){
					lnk[s[i-1]-'a'][0]=s[i]-'a';
					lnk[s[i]-'a'][1]=s[i-1]-'a';
					co[s[i-1]-'a'][s[i]-'a']=co[s[i]-'a'][s[i-1]-'a']=1;
					continue;
				}
			}
			if(lnk[s[i-1]-'a'][1]==-1&&lnk[s[i]-'a'][0]==-1){
				int j=s[i-1]-'a';
				while(j!=-1){
					if(j==s[i]-'a'){
						break;
					}
					j=lnk[j][0];
				}
				if(j==-1){
					lnk[s[i-1]-'a'][1]=s[i]-'a';
					lnk[s[i]-'a'][0]=s[i-1]-'a';
					co[s[i-1]-'a'][s[i]-'a']=co[s[i]-'a'][s[i-1]-'a']=1;
					continue;
				}
			}
			flag=0;
			break;
		}
		if(flag){
			puts("YES");
			for(int i=0;i<26;i++){
				if(vis[i]){
					continue;
				}
				int j=i;
				while(lnk[j][0]!=-1){
					j=lnk[j][0];
				}
				while(j!=-1){
					putchar((char)(j+'a'));
					vis[j]=1;
					j=lnk[j][1];
				}
			}
			puts("");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}