#include <cstdio>
#include <set>

int n,stk[200001],top,pos[100001],ans[200001],mx[200001];
bool vis[200001];
std::set<int>set;
int main(){
	scanf("%d",&n);
	set.insert(0);
	for(int i=1;i<=(n<<1);i++){
		char ch=getchar();
		while(ch!='-'&&ch!='+')ch=getchar();
		if(ch=='+'){
			stk[++top]=i;
			mx[top]=0;
		}
		else{
			int x;
			scanf("%d",&x);
			if(!top){
				puts("NO");
				return 0;
			}
			if(mx[top]>x){
				puts("NO");
				return 0;
			}
			mx[top-1]=std::max(mx[top-1],x);
			ans[stk[top]]=x;
			--top;
		}
	}
	puts("YES");
	for(int i=1;i<=(n<<1);i++)
		if(ans[i])printf("%d ",ans[i]);
}