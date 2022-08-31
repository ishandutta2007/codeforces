#include <cstdio>
#include <vector> 
#include <cstring>

int t;
std::vector<int>ans;
int fin[150001],top;
char str[150001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%s",str+1);
		ans.clear();
		int nl=strlen(str+1);
		for(int i=2;i<nl;i++){
			if(str[i-1]=='o'&&str[i]=='n'&&str[i+1]=='e')ans.push_back(i);
			if(str[i-1]=='t'&&str[i]=='w'&&str[i+1]=='o')ans.push_back(i);
		}
		top=0;
		for(int i=0;i<ans.size();i++)
			if(i<ans.size()-1&&ans[i]==ans[i+1]-2)fin[++top]=ans[i]+1,++i;
			else fin[++top]=ans[i];
		for(int i=1;i<=nl;i++)str[i]=0;
		printf("%d\n",top);
		for(int i=1;i<=top;i++)printf("%d ",fin[i]);putchar('\n');
	}
}