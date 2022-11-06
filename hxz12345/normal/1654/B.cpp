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
int n,mx,i,cnt[100101];
char s[1001010];
void Main(){
    scanf("%s",s+1);n=strlen(s+1);
    for (i=0;i<26;i++) cnt[i]=0;
    for (i=1;i<=n;i++) cnt[s[i]-'a']++;
    mx=-1;
    for (i=1;i<=n;i++){
    	if (cnt[s[i]-'a']==1){
    		mx=i;break;
		}cnt[s[i]-'a']--;
	}
	for (i=mx;i<=n;i++) printf("%c",s[i]);
	puts("");
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
    return 0;
}