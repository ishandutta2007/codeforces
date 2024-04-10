#include<cstdio>
#include<string>

using namespace std;

char a[200][200];
string S="theseus";

int main()
{
	int n=0;scanf("%d",&n);for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf(" %c",&a[i][j]);
	
	/*for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){bool f=1;for(int k=0;k<7;k++)if(a[i][j+k]!=S[k]){f=0;break;}if(f){puts("YES");return 0;}}}
	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){bool f=1;for(int k=0;k<7;k++)if(a[i+k][j]!=S[k]){f=0;break;}if(f){puts("YES");return 0;}}}
	for(int i=1;i<=n;i++){for(int j=7;j<=n;j++){bool f=1;for(int k=0;k<7;k++)if(a[i][j-k]!=S[k]){f=0;break;}if(f){puts("YES");return 0;}}}
	for(int i=7;i<=n;i++){for(int j=1;j<=n;j++){bool f=1;for(int k=0;k<7;k++)if(a[i-k][j]!=S[k]){f=0;break;}if(f){puts("YES");return 0;}}}
	*/
	
	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){bool f=1;for(int k=0;k<7;k++)if(a[i+k][j+k]!=S[k]){f=0;break;}if(f&&(i==1||j==1||i+6==n||j+6==n)){puts("YES");return 0;}}}
	//for(int i=1;i<=n;i++){for(int j=7;j<=n;j++){bool f=1;for(int k=0;k<7;k++)if(a[i+k][j-k]!=S[k]){f=0;break;}if(f&&(i==1||j==n||i+6==n||j-6==1)){puts("YES");return 0;}}}
	//for(int i=7;i<=n;i++){for(int j=1;j<=n;j++){bool f=1;for(int k=0;k<7;k++)if(a[i-k][j+k]!=S[k]){f=0;break;}if(f&&(i==n||j==1||i-6==1||j+6==n)){puts("YES");return 0;}}}
	//for(int i=7;i<=n;i++){for(int j=7;j<=n;j++){bool f=1;for(int k=0;k<7;k++)if(a[i-k][j-k]!=S[k]){f=0;break;}if(f&&(i==n||j==n||i-6==1||j-6==1)){puts("YES");return 0;}}}
	
	puts("NO");
}