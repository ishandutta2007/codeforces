#include<bits/stdc++.h>
char a[13][13];
bool f[13][13];
int bc[13][13];
int br[13][13];
void init(void) {
	int i,j,nb;
	nb=0;
	for (i=0;i<8;i=i+1) scanf("%s",a[i]);
	for (i=0;i<8;i=i+1)
		for (j=0;j<8;j=j+1) {
			nb=nb+(a[i][j]=='B');
			if (i>0) bc[i][j]=bc[i-1][j]+(a[i][j]=='B');			
			else bc[i][j]=(a[i][j]=='B');
			if (j>0) br[i][j]=br[i][j-1]+(a[i][j]=='B');
			else br[i][j]=(a[i][j]=='B');
		}
	if (nb==64) {
		printf("8");
		exit(0);
	}
}
void process(void) {
	int i,j,k;
	int res=0;
	for (i=0;i<8;i=i+1) {
		if (br[i][7]<8) {
			for (j=0;j<8;j=j+1)
				if (a[i][j]=='B' && !f[i][j]) {
					res++;
					for (k=0;k<8;k=k+1)	f[k][j]=true;
				}
		}
		if (bc[7][i]<8) {
			for (j=0;j<8;j=j+1)
				if (a[j][i]=='B' && !f[j][i]) {
					res++;
					for (k=0;k<8;k=k+1) f[j][k]=true;
				}
		}
	}	
	printf("%d",res);
}
int main(void) {
	//freopen("tmp.txt","r",stdin);
	init();
	process();
	return 0;
}