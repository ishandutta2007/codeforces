//Time Complexity : O(N)
//Space Complexity : O(N)
#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
int main(){
	int n;
	char s[N+2]={};
	int st[N+1]={};
	int top=0;
	bool v[N+2]={};
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i){
		switch(s[i]){
			case '(':
				st[++top]=i;
				break;
			case ')':
				if(top){
					v[i]=1;
					v[st[top--]]=1;
				}
				break;
		}
	}
	int ans=-1,cnt=0;
	for(int i=1,j=0;i<=n+1;++i){
		if(v[i]){
			++j;
		}else{
			if(j>ans){
				ans=j;
				cnt=1;
			}else if(ans&&j==ans){
				++cnt;
			}
			j=0;
		}
	}
	printf("%d %d\n",ans,cnt);
	return 0;
}