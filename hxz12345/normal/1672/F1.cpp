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
map<int,vector<int>>mp;
vector<int> G[201010];
int lst,k,i,ans,tot,n,m,a[201010],b[201010];
void Main(){
	n=read();mp.clear();
	for (i=1;i<=n;i++){
		a[i]=read();mp[a[i]].push_back(i);
	}
	ans=0;tot=0;
	while (ans<n){
		for (auto&i:mp){
			if (i.second.size()==0) continue;
			else{
				G[tot].push_back(i.second.back());
				ans++;i.second.pop_back();
			}
		}tot++;
	}
	for (i=0;i<tot;i++){
		lst=0;k=0;
		for (auto j:G[i])
		    if (lst==0) lst=k=j;
		    else b[lst]=a[j],lst=j;
	b[lst]=a[k];G[i].clear();}
	for (i=1;i<=n;i++) printf("%d ",b[i]);
	puts("");
	return ;
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}