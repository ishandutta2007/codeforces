#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;

}
long long n,i,B,C,A;
char S[1001010];
void Main(){
	n=read();
scanf("%s",S+1);S[n+1]='W';B=0;C=0;A=1;
for (i=1;i<=n+1;i++){
	if (S[i]=='W'&&B+C==1) A=0;
	if (S[i]=='W') B=0,C=0;
	if (S[i]=='R') B=1;
	if (S[i]=='B') C=1;
}
if (A==0) puts("NO");else puts("YES");
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}