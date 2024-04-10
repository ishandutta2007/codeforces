
#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int x[26];
char a[200005];
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",a+1);
	for(int i=1,last=-1,len=0;i<=n;++i){
		if(a[i]-'a'!=last){
			last=a[i]-'a';
			len=0;
		}
		if(++len==k){
			len=0;
			++x[last];
		}
	}
	for(int i=0;i<26;++i){
		ans=max(ans,x[i]);
	}
	printf("%d",ans);
	return 0;
}