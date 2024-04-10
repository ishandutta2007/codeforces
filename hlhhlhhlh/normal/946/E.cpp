#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k;
int n,len,fla,a[maxn],ha[10];
char c;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c-'0'<0)||(c-'0'>9)){ if(c=='-') fh=-1; c=getchar(); }
	while ((c-'0'>=0)&&(c-'0'<=9)){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
void work(){
	int i,j,k,t1,t2;
	memset(ha,0,sizeof(ha));
	for (i=1;i<=len;i++) ha[a[i]]++;
	for (i=len;i>=1;i--){
		ha[a[i]]--;
		for (j=a[i]-1;j>=0;j--){
			ha[j]++; t1=0;
			for (k=0;k<=9;k++){
				if (ha[k]%2==1) t1++; 
			}
			if (t1<=len-i){
				for (k=1;k<=i-1;k++) printf("%d",a[k]); printf("%d",j);
				for (k=1;k<=len-i-t1;k++) printf("9");
				for (k=9;k>=0;k--){
					if (ha[k]%2==1) printf("%d",k);
				}
				printf("\n");
				return;
			}
			ha[j]--;
		}
	}
}
int main(){
	n=read();
	for (i=1;i<=n;i++){
		c=getchar(); len=0;
		while ((c-'0'<0)||(c-'0'>9)){ c=getchar(); }
		while ((c-'0'>=0)&&(c-'0'<=9)){ len++; a[len]=c-'0'; c=getchar(); }
		fla=1;
		for (j=2;j<=len-1;j++){
			if (a[j]!=0) fla=0;
		}
		if (a[1]==1) fla++;
		if (a[len]<=1) fla++;
		if (fla==3){
			for (j=1;j<=len-2;j++) printf("9");
			printf("\n"); continue;
		}
		work();
	}
	return 0;
}