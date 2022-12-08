#include<bits/stdc++.h>
using namespace std;
const int N=1e3+3;
char ch[N];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int len;
		scanf("%d",&len);
		scanf("%s",ch+1);
		int flag=1;
		for(int i=1;i<=len/2;i++){
			int j=len-i+1;
			if(ch[i]-ch[j]!=0&&abs(ch[i]-ch[j])!=2){
				printf("NO\n");
				flag=0;
				break;
			}
		}
		if(flag)printf("YES\n");
	}
}