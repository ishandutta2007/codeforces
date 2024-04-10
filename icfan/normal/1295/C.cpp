#include <set>
#include <cstdio>
using namespace std;
const int Maxn=100000;
char s[Maxn+5],t[Maxn+5];
int sqam[Maxn+5][26];
int n_s,n_t;
int main(){
	int T;
	scanf("%d",&T);
	bool flag;
	int ans;
	while(T--){
		n_s=n_t=0;
		scanf("%s",s+1);
		scanf("%s",t+1);
		while(s[++n_s]!='\0');
		n_s--;
		while(t[++n_t]!='\0');
		n_t--;
		for(int i=0;i<26;i++){
			sqam[n_s][i]=n_s+1;
		}
		for(int i=n_s-1;i>=0;i--){
			for(int j=0;j<26;j++){
				sqam[i][j]=sqam[i+1][j];
			}
			sqam[i][s[i+1]-'a']=i+1;
		}
		flag=0;
		for(int i=1;i<=n_t;i++){
			if(sqam[0][t[i]-'a']==n_s+1){
				flag=1;
				break;
			}
		}
		if(flag){
			puts("-1");
			continue;
		}
		ans=1;
		for(int i=1,j=0;i<=n_t;i++){
			j=sqam[j][t[i]-'a'];
			if(j==n_s+1){
				j=sqam[0][t[i]-'a'];
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}