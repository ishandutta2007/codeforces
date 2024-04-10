#include <cstdio>

int n,a,stk[1000001],top,ans,last=1;
char str[1000001];
int main(){
	scanf("%d",&n);
	scanf("%s",str+1);
	bool bad=0;
	for(int i=1;i<=n;i++){
		a+=(str[i]=='(')?1:-1;
		if(str[i]=='(')stk[++top]=i;
		else{
			if(top)--top;
			else bad=1;
		}
		if(!a){
			if(top||bad)ans+=i-last+1;
			top=0,bad=0;
			last=i+1;
		}
	}
	if(a)puts("-1");
	else printf("%d\n",ans);
}