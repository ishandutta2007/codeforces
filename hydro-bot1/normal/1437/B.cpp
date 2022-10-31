// Hydro submission #618e10da609bbc8c787346ac@1636700388595
#include<bits/stdc++.h>
using namespace std;
vector<int> edge[200005];
char s[200005];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		scanf("%s",s+1); 
//		int n,m;
//		scanf("%d%d",&n,&m);
		int now=0;
		int sum1=0,sum2=0;
		for(int i=1;i<=n;i++)
			if(s[i]==s[i-1])now++;
			else{
				if(s[i-1]=='0')sum1+=now-1;
				if(s[i-1]=='1')sum2+=now-1;
				now=1;
			}
		printf("%d\n",max(sum1,sum2));
	}
	return 0;
}