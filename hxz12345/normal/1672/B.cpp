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
int n,i,x,y;
char S[1001010];
void Main(){
	scanf("%s",S+1);
	n=strlen(S+1);
	x=0;y=0;//ABAB
	//ABAB
	//ABB
	//A
	if (S[n]!='B'){puts("NO");return ;}
	for (i=1;i<=n;i++){
		x+=(S[i]=='A');y+=(S[i]=='B');
		if (y>x){
			puts("NO");return ;
		}
	}
	puts("YES");
	return ;
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}