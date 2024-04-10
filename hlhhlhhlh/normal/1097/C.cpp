// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
int i,j,k;
int n,l[maxn],r[maxn],a[maxn],th,b[maxn];
char c=' ';
int thi,fla,ans0,ans1;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
map <int,int> mp;
int main(){
	n=read();
	for (i=1;i<=n;i++){
		while ((c!='(')&&(c!=')')){ c=getchar(); }
		l[i]=th+1;
		while ((c=='(')||(c==')')){
			th++; a[th]=c;
			c=getchar();
		}
		r[i]=th;
	}
	for (i=1;i<=n;i++){
		for (j=l[i];j<=r[i];j++){
			b[i]=b[i]+(a[j]=='(');
			b[i]=b[i]-(a[j]==')');
		}
		if (b[i]==0){
			thi=0; fla=1;
			for (j=l[i];j<=r[i];j++){
				thi=thi+(a[j]=='(');
				thi=thi-(a[j]==')');
				if (thi<0) fla=0;
			}
			if (fla==1) ans0++;
		}
		if (b[i]>0){
			thi=0; fla=1;
			for (j=l[i];j<=r[i];j++){
				thi=thi+(a[j]=='(');
				thi=thi-(a[j]==')');
				if (thi<0) fla=0;
			}
			if (fla==1) mp[thi]++;
		}
	}
	for (i=1;i<=n;i++){
		if (b[i]<0){
			thi=0; fla=1;
			for (j=r[i];j>=l[i];j--){
				thi=thi+(a[j]=='(');
				thi=thi-(a[j]==')');
				if (thi>0) fla=0;
			}
			if (fla==1){
				if (mp[-thi]!=0){
					ans1++; mp[-thi]--;
				}
			}
		}
	}
	printf("%d\n",ans1+ans0/2);
	return 0;
}