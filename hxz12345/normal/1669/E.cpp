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
map<long long,long long> mp1,mp2;
map<pair<long long,long long>,long long>mp;
long long 
A,B,C,D,ans,a[1001010][2],n,i;
char S[1001010];

void Main(){
  n=read();mp.clear();mp1.clear();mp2.clear();
  for (i=1;i<=n;i++){
  	 scanf("%s",S+1);
  	 a[i][1]=S[1];a[i][2]=S[2];
  	 mp[make_pair(a[i][1],a[i][2])]++;
  	 mp1[a[i][1]]++;
  	 mp2[a[i][2]]++;
  }ans=0;
  for (A='a';A<='k';A++)
  
  for (B='a';B<='k'; B++)
  
  for (C='a';C<='k';C++)
  
  for (D='a';D<='k';D++)
      if ((A==C)+(B==D)==1) ans+=mp[make_pair(A,B)]*mp[make_pair(C,D)];
  printf("%lld\n",ans/2);
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}