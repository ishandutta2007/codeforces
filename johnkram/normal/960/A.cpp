#include<bits/stdc++.h>
using namespace std;
char c[5005];
int n,i,a[10];
bool check()
{
	for(i=0;i+1<n;i++)if(c[i]>c[i+1])return 0;
	for(i=0;i<n;i++)if(c[i]<'a'||c[i]>'c')return 0;
	for(i=0;i<n;i++)a[c[i]-'a']++;
	return a[0]&&a[1]&&(a[2]==a[0]||a[2]==a[1]);
}
int main()
{
	scanf("%s",c);
	n=strlen(c);
	if(check())puts("YES");
	else puts("NO");
	return 0;
}