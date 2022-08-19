#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
 
int t,n,cnt[2][2],tem[2];
char a[4001],b[4001];
std::vector<int>ans;
void reverse(const int &x){
	if(!x)return;
//	printf("%s ",a+1);
	std::reverse(a+1,a+x+1);
//	printf("%s\n",a+1);
	ans.push_back(x);
}
int main(){
//	freopen("out.txt","w",stdout);
	scanf("%d",&t);
//	t=1;
	for(int fd=1;fd<=t;fd++){
		scanf("%s%s",a+1,b+1);
		n=strlen(a+1);
//		n=4000;
//		for(int i=1;i<=n;i++)a[i]=rand()%2+'0';
//		for(int i=1;i<=n;i++)b[i]=rand()%2+'0';
//		a[n+1]=b[n+1]=0;
//		printf("%s\n%s\n",a+1,b+1);
		ans.clear();
		int sum=0;
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i+=2)++cnt[a[i]-'0'][a[i+1]-'0'];
		for(int i=1;i<=n;i+=2)--cnt[b[i+1]-'0'][b[i]-'0'];
//		printf("%d %d %d %d\n",cnt[0][0],cnt[1][1],cnt[0][1],cnt[1][0]);
		if(cnt[0][0]||cnt[1][1]){
			puts("-1");
			continue;
		}
		int magic=0;
		if(cnt[1][0]){
			bool cando=0;
			for(int i=1,ind=0;i<=n;i+=2){
				memset(cnt,0,sizeof cnt);
				reverse(i+1);
				for(int i=1;i<=n;i+=2)++cnt[a[i]-'0'][a[i+1]-'0'];
				for(int i=1;i<=n;i+=2)--cnt[b[i+1]-'0'][b[i]-'0'];
				if(!cnt[1][0]&&!cnt[0][1]){
					cando=1;
					break;
				}
				else reverse(i+1),ans.clear();
			}
			if(!cando)
				for(int i=1,ind=0;i<=n;i+=2){
					memset(cnt,0,sizeof cnt);
					std::reverse(b+1,b+i+2);
					for(int i=1;i<=n;i+=2)++cnt[a[i]-'0'][a[i+1]-'0'];
					for(int i=1;i<=n;i+=2)--cnt[b[i+1]-'0'][b[i]-'0'];
					if(!cnt[1][0]&&!cnt[0][1]){
						cando=1;
						magic=i+1;
						break;
					}
					else std::reverse(b+1,b+i+2);
				}
			if(!cando){
				puts("-1");
				continue;
			}
		}
		for(int i=1;i<=n;i+=2){
			for(int j=i;j<=n;j+=2){
				if(a[j]==b[n-i+1]&&a[j+1]==b[n-i]){
					reverse(j-1);
					reverse(j+1);
//		printf("%s\n\n",a+1);
					break;
				}
			}
		}
		printf("%d\n",ans.size()+(magic!=0));
//		printf("%d\n",magic);
		for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);if(magic)printf("%d ",magic);putchar('\n');
//		if(magic)std::reverse(b+1,b+magic+1);
//		for(int i=1;i<=n;i++)assert(a[i]==b[i]);
//		printf("%s\n",a+1); 
	}
}