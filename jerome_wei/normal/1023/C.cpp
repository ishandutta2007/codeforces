#include<bits/stdc++.h>

using namespace std;
const int N=2e5+5;
int n,m;

char ch[N];

int s[N];

int pre[N];

int main()
{
	scanf("%d%d",&n,&m);
	int k=n-m;
	k/=2;
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++){
		if(ch[i]=='('&&k==0)s[i]=1;
		else if(ch[i]=='('){
			k--;
			s[i]=0;
		}
		else s[i]=-1;
		pre[i]=pre[i-1]+s[i];
		if(s[i]==-1&&pre[i]<0){
			pre[i]++;
			s[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i]>0)printf("(");
		else if(s[i]<0)printf(")");
	}
}