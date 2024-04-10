/*********************************************************************
	Problem:CF1221E
	Author:hydd
	Date:2020/7/18
*********************************************************************/
#include<cstdio>
#include<cstring>
#define File(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
int T,a,b,n,cnt,v[1100000];
char s[1100000];
bool check(){
	int tot=0,tot2=0,tmp;
	for (int i=1;i<=cnt;i++){
		if (b<=v[i]&&v[i]<a) return false;
		if (a<=v[i]&&v[i]<2*b) tot++;
		if (v[i]>=2*b) tmp=v[i],tot2++;
	}
	if (tot2==0) return tot&1;
	if (tot2>1) return false;
	for (int i=1;i<=tmp-a+1;i++){//1<=i..i+a-1<=tmp
		int l=i-1,r=tmp-(i+a-1);
		if (l>=2*b||r>=2*b||(b<=l&&l<a)||(b<=r&&r<a)) continue;
		int d=(a<=l&&l<2*b)+(a<=r&&r<2*b);
		if (!((tot+d)&1)) return true;
	}
	return false;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&a,&b);
		scanf("%s",s); n=strlen(s);
		cnt=0;
		for (int i=0,j;i<n;i=j+1){
			j=i;
			while (j<n&&s[j]=='.') j++;
			if (i!=j) v[++cnt]=j-i;
		}
		if (check()) puts("YES");
		else puts("NO");
	}
	return 0;
}