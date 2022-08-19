#include <cstdio>
#include <cstring>

int n,fst[200001][26],nl;
char str[200001];
int main(){
	scanf("%s",str+1);
	nl=strlen(str+1);
	for(int i=1;i<=nl;i++){
		for(int j=0;j<26;j++)fst[i][j]=fst[i-1][j];
		fst[i][str[i]-'a']=i;
	}
	scanf("%d",&n);
	for(int i=1,l,r;i<=n;i++){
		scanf("%d%d",&l,&r);
		if(l==r)puts("Yes");
		else if(str[l]!=str[r])puts("Yes"); 
		else{
			int cnt=0;
			for(int i=0;i<26;i++)if(fst[r][i]>=l)++cnt;
			if(cnt>2)puts("Yes");
			else puts("No");
		}
	}
}