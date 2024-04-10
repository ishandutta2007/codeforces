#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n;
char a[N];
int s[30];
int main()
{
	scanf("%d",&n);
	scanf("%s",a+1);
	for(int i=1;i<=n;i++){
		s[a[i]-'a']++;
	}
	int flag1=0;
	int flag2=0;
	for(int i=0;i<26;i++){
		if(s[i]==0)continue;
		//cout<<s[i];
		if(s[i]==1)flag1=1;
		if(s[i]>=2)flag2=1;
	}
	if(flag2){
		printf("Yes\n");
		return 0;
	}
	else if(flag1&&n>1){
		printf("No\n");
		return 0;
	}
	if(n==1)printf("Yes\n");
	return 0;
}