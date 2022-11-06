#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}struct node{
int x,y;};
int tot,n,i;
map<int,int> mp;
vector<node> G1;
vector<int> G2;deque<int> a,G3;
inline bool check(){
	if (n%2==1) return false;
	for(int i=0;i<n/2;i++) if(a[i]!=a[i+(n/2)]) return false;
	return true;
}
void Main(){
   mp.clear();G1.clear();G2.clear();G3.clear();a.clear();
   tot=0;n=read();a.resize(n);
	for(int i=0;i<n;i++) a[i]=read(),mp[a[i]]++;
	for(auto i:mp)if(i.second&1){puts("-1");return ;}
	while(!a.empty()){
		n=a.size();
		if(check()){G2.push_back(n);break;}int tag=0;
		for (i=1;i<n;i++) if (a[i]==a[0]){tag=i;break;}
		G2.push_back(tag*2);G3.clear();
		for(int i=1;i<tag;i++){G1.push_back({i+tot+tag,a[i]});G3.push_front(a[i]);}
		for(int i=0;i<=tag;i++)a.pop_front();
		while(!G3.empty()){a.push_front(G3.back());G3.pop_back();}
		tot+=tag*2;
	}
	printf("%d\n",(int)G1.size());
	for(auto i:G1) printf("%d %d\n",i.x,i.y);
	printf("%d\n",(int)G2.size());
	for(auto i:G2) printf("%d ",i);
	puts("");
}
int main()
{
	int Testing;
	Testing=read();
	for (;Testing;Testing--) Main();
    return 0;
}