#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
char st[N];
int s1,s2,sum,now,b[N],lsum[N],rsum[N],lmn[N],rmn[N];
int main(){
	scanf("%s",st+1);
	int n=strlen(st+1);
	for(int i=1;i<=n;i++){
		if(st[i]=='(')s1++;
		else s2++;
	}
	if(s1<s2)sum=s2-s1;
	rmn[n+1]=1e9,lmn[0]=1e9;
	for(int i=n;i;i--)rsum[i]=rsum[i+1]+(st[i]=='('?1:-1),rmn[i]=min(rmn[i+1]+(st[i]=='('?1:-1),(st[i]=='('?1:-1));
	for(int i=1;i<=n;i++)lsum[i]=lsum[i-1]+(st[i]=='('?1:-1),lmn[i]=min(lmn[i-1],lsum[i]);
	for(int i=n;i>=1;i--){
		if(min(rmn[i],rsum[i]+lmn[i-1])+sum>=0){
			b[i]=1;
		}
	}
	for(int i=n+1;i<=2*n;i++)st[i]=st[i-n];
	int i=1,j=2,k;
	while(i<=n&&j<=n){
		while(!b[i]&&i<=n)i++;
		while(!b[j]&&j<=n)j++;
		if(i>n||j>n)break;//
		if(i==j){
			j++;
			continue;
		}
		for(k=0;k<=n&&st[i+k]==st[j+k];k++);
		if(k==n)break;
		if(st[i+k]>st[j+k]){
			i=i+k+1;
			if(i==j)i++;
		}
		else{
			j=j+k+1;
			if(i==j)j++;
		}
	}
	int ans=min(i,j);
	if(s1<s2)for(int i=1;i<=s2-s1;i++)putchar('(');
	for(int i=ans;i<=ans+n-1;i++)putchar(st[i]);
	if(s2<s1)for(int i=1;i<=s1-s2;i++)putchar(')');
}