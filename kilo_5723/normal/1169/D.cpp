#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=3e5+5;
char s[maxn];
int main(){
	int i,j,n,r;
	ll ans=0;
	scanf("%s",s);
	n=strlen(s); r=n;
	for (i=n-1;i>=0;i--){
		for (j=i+1;j+j-i<r;j++){
			if (s[i]==s[j]&&s[i]==s[j+j-i]){
				r=j+j-i; break;
			}
		}
		ans+=n-r;
	}
	printf("%lld\n",ans);
	return 0;
}