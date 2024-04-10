#include <cstdio>
#include <cstring>

const int P=1000000007;
int t,x,nl,now;
char str[1000001];
void add(int l,int r,int t){
	for(int i=1;i<=t;i++){
		for(int j=l;j<=r;j++){
			if(now>x)return;
			str[now]=str[j];
			++now;
		}
	}
}
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&x);
		scanf("%s",str+1);
		nl=strlen(str+1);
		int ans=nl;
		now=nl+1;
		for(int i=1;i<=x;i++){
			add(i+1,ans,str[i]-'0'-1);
			ans=1ll*(1ll*(ans+P-i)*(str[i]-'0')%P+i)%P;
		}
		for(int i=1;i<=nl||i<=x;i++)str[i]=0;
		printf("%d\n",ans);
	}
}