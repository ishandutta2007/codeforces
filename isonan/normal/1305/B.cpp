#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

char str[1001];
int n,f[1001],g[1001],cnt,s[2][1001];
std::vector<int>pos,ans;
int main(){
	scanf("%s",str+1);
	n=strlen(str+1);
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(str[j]=='(')++cnt;
			else if(str[j]==')'&&cnt){
				cnt=-1;
				break;
			}
		}
		if(~cnt)break;
		for(int j=1;j<=n;j++){
			if(str[j]=='('){
				ans.push_back(j);
				str[j]=0;
				break;
			}
		}
		for(int j=n;j;j--){
			if(str[j]==')'){
				ans.push_back(j);
				str[j]=0;
				break;
			}
		}
	}
	if(!ans.size())puts("0");
	else{
		printf("1\n");
		printf("%d\n",ans.size());
		std::sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
	}
}