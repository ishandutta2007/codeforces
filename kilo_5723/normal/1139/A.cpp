#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
char s[maxn];
int main(){
	int i,n;
	ll ans;
	scanf("%d",&n);
	scanf("%s",&s);
	ans=0;
	for (i=0;i<n;i++) if ((s[i]-'0'+1)&1)
		ans+=i+1;
	printf("%I64d\n",ans);
	return 0;
}