#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[1100][1100],b[3][1100000],c[3],t[3];
char s[1100000];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m); int cnt=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++){
				scanf("%d",&a[i][j]); a[i][j]--;
				b[0][cnt]=i; b[1][cnt]=j; b[2][cnt]=a[i][j]; cnt++;
			}
		c[0]=0; c[1]=1; c[2]=2;
		t[0]=0; t[1]=0; t[2]=0;
		scanf("%s",s); int len=strlen(s);
		for (int i=0;i<len;i++)
			switch (s[i]){
				case 'R':{
					t[c[1]]++;
					break;
				}
				case 'L':{
					t[c[1]]--;
					break;
				}
				case 'D':{
					t[c[0]]++;
					break;
				}
				case 'U':{
					t[c[0]]--;
					break;
				}
				case 'I':{
					swap(c[1],c[2]);
					break;
				}
				case 'C':{
					swap(c[0],c[2]);
					break;
				}
			}
		for (int i=0;i<cnt;i++) b[0][i]=(b[0][i]+t[0]%n+n)%n;
		for (int i=0;i<cnt;i++) b[1][i]=(b[1][i]+t[1]%n+n)%n;
		for (int i=0;i<cnt;i++) b[2][i]=(b[2][i]+t[2]%n+n)%n;
		for (int i=0;i<cnt;i++) a[b[c[0]][i]][b[c[1]][i]]=b[c[2]][i];
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++)
				printf("%d ",a[i][j]+1);
			putchar('\n');
		}
	}
	return 0;
}