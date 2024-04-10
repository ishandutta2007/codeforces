#include<bits/stdc++.h>
using namespace std;
char s[100005];
int n,i,a[26];
int main()
{
	scanf("%d%s",&n,s);
	for(i=0;i<n;i++)a[s[i]-'a']++;
	for(i=0;i<26;i++)while(a[i]--)putchar(i+'a');
	return 0;
}