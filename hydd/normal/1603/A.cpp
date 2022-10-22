#include<bits/stdc++.h>
using namespace std;
int T,n,a[110000];
bool work(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=n;i>=1;i--){
		int pos=i;
		while (pos&&a[pos]%(pos+1)==0) pos--;
		if (!pos) return false;
		for (int j=pos;j<i;j++) a[j]=a[j+1];
	}
	return true;
}
int main(){
	scanf("%d",&T);
	while (T--)
		if (work()) puts("YES");
		else puts("NO");
	return 0;
}