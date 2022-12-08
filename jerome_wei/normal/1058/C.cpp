#include<bits/stdc++.h>
using namespace std;
int n,sum[110];
int s;

int gett()
{
	char x=0;
	while(x<'0'||x>'9')x=getchar();
	return x-'0';
}

inline bool chk(int pp){
	int pos=0,su=0;
	int prt=0;
	for(int i=1;i<=n;i++){
		if(su==0&&sum[i]==0)pos=i;
		su+=sum[i];
		if(su>pp)return false;
		if(su==pp)pos=i,prt++,su=0;
	}
	if(pos==n&&prt>1)return true;
	return false;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){sum[i]=gett();s+=sum[i];}
	for(int i=1;i<s;i++)if(s%i==0){
		bool res=chk(i);
		if(res){printf("YES\n");return 0;}	
	}
	if(s==0)printf("YES\n");
	else printf("NO\n");
}