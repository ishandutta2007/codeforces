#include<bits/stdc++.h>
using namespace std;
#define N 200005
int n,m,sum[N][10];
char s[N];
void solve(){
	for(int i=n;i>=1;i--){
		for(int j=s[i]-'0'-1;j>=0;j--){
			if(i==1&&j==0)continue;
			int now=0;
			for(int k=0;k<10;k++)now+=sum[i-1][k]^(j==k);
			if(now<=n-i){
				for(int k=1;k<i;k++)putchar(s[k]);
				putchar(j+'0');
				for(int k=i+1;k<=n-now;k++)putchar('9');
				for(int k=9;k>=0;k--)
					if(sum[i-1][k]^(j==k))putchar(k+'0');
				puts("");
				return;
			}
		}
	}
	for(int i=1;i<=n-2;i++)putchar('9');
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);n=strlen(s+1);
		for(int i=1;i<=n;i++){
			int id=s[i]-'0';
			for(int k=0;k<10;k++)
				sum[i][k]=sum[i-1][k]^(id==k);
		}
		solve();
	}
}