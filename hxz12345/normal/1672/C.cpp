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
bool flag;
vector<pair<int,int>> G;
int GG,n,lst,ttt,up,i,a[1001010],m,ans,sum;
void Main(){
	n=read();
	//1 2 1 2 1 2 
	for (i=1;i<=n;i++) a[i]=read();
    G.clear();
    ans=1;
       
    for (i=2;i<=n;i++)
        if (a[i]==a[i-1]) ans++;
    else {
    	if (ans>1) G.push_back({i-ans,i-1});
    	ans=1;
	}
	if (ans>1) G.push_back({n-ans+1,n});
	if (G.size()==0) puts("0");
	else if (G.size()==1) {
		int k=G[0].second-G[0].first;
		if(k==1) puts("0");
		else if(k==2||k==3) puts("1");
		else  printf("%d\n",k-2);
	}else printf("%d\n",G[G.size()-1].second-G[0].first-2);
	return ;
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}