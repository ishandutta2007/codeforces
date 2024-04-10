// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int n,a[maxn],b[maxn],ha[maxn],ans;
int c[maxn],d[maxn],l,r;
int main(){
	
	n=read();
	for (i=1;i<=n;i++) a[i]=read();
	for (i=n;i>=1;i--){
		b[i]=ha[a[i]];
		if (b[i]==0) b[i]=n+1;
		ha[a[i]]=i;
	}
	for (i=1;i<=n;i++){
		if (c[l]==0){
			l++; c[l]=i;
		}
		else{
			if (a[c[l]]==a[i]){
				l++; c[l]=i;
			}
			else{
				if (d[r]==0){
					r++; d[r]=i;
				}
				else{
					if (a[d[r]]==a[i]){
						r++; d[r]=i;
					}
					else{
						if (b[d[r]]<b[c[l]]){
							l++; c[l]=i;
						}
						else{
							r++; d[r]=i;
						}
					}
				}
			}
		}
	}
	for (i=1;i<l;i++) if (a[c[i]]!=a[c[i+1]]) ans++; if (l!=0) ans++;
	for (i=1;i<r;i++) if (a[d[i]]!=a[d[i+1]]) ans++; if (r!=0) ans++;
	printf("%d\n",ans);
	return 0;
}