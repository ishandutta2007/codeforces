#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A[3000],B[3000];
char ch[110000];
int main(){
	scanf("%s",ch+1); int n=strlen(ch+1);
	string s="Bulbasaur";
	for (int i=0;i<s.length();i++) B[s[i]]++;
	for (int i=1;i<=n;i++) A[ch[i]]++;
	int ans=n;
	for (int i=0;i<s.length();i++) ans=min(ans,A[s[i]]/B[s[i]]);
	cout<<ans<<endl;
}