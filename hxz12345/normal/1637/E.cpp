#include <bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char ch=getchar();
	while ((!isdigit(ch))&&(ch!='-')) ch=getchar();
	if (ch=='-') f=-1,ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return x*f;
}
map<pair<int,int>,bool> exist;
vector<int> E[1001010];
vector<long long> V[1001010];
long long j,ans,lst,nxt,x,lft,rit,now,a[1001010],b[1001010],fre[1001010],n,m,i,c[1001010],tn,w,la[1001010],lb[1001010],tag[1001010];
bool check(long long x,long long y){if (x==y) return false;return exist[make_pair(x,y)]==false;}
void Main(){
	n=read();m=read();exist.clear();
	for (i=1;i<=n;i++) a[i]=read(),c[i]=a[i];sort(c+1,c+n+1);tn=unique(c+1,c+n+1)-c-1;
	for (i=1;i<=n;i++) a[i]=lower_bound(c+1,c+tn+1,a[i])-c;
	for (i=1;i<=n;i++) fre[a[i]]++;w=0;
	for (i=1;i<=n;i++) if (fre[i]) b[++w]=fre[i];
	sort(b+1,b+w+1);w=unique(b+1,b+w+1)-b-1;
	for (i=1;i<=n;i++) if (fre[i]) V[fre[i]].push_back(i);
	for (i=1;i<=m;i++){
	    la[i]=read();lb[i]=read();
	    la[i]=lower_bound(c+1,c+tn+1,la[i])-c;lb[i]=lower_bound(c+1,c+tn+1,lb[i])-c;
	    exist[make_pair(la[i],lb[i])]=1;exist[make_pair(lb[i],la[i])]=1;
        E[la[i]].push_back(lb[i]);E[lb[i]].push_back(la[i]);
	}
	for (i=1;i<=w;i++)
	   for (j=0;j<V[i].size();j++)
	         tag[V[i][j]]=j+1;
	ans=0;
	for (lst=1;lst<=w;lst++)
		  for (i=0;i<V[b[lst]].size();i++)
	           {
	           	     now=V[b[lst]][i];
	           	     for (j=0;j<E[now].size();j++)
	           	          {
	           	          	   nxt=E[now][j];x=tag[nxt];
	           	          	   if (x!=1)
	           	          	       if (check(now,V[fre[nxt]][x-2]))
	           	          	             ans=max(ans,(b[lst]+fre[nxt])*(c[now]+c[V[fre[nxt]][x-2]]));
							 }
			   }
	for (lst=1;lst<=w;lst++)
	    if (V[b[lst]].size()>1){
	      lft=V[b[lst]][V[b[lst]].size()-1];rit=V[b[lst]][V[b[lst]].size()-2];
	   	  if (check(lft,rit))
	   	     ans=max(ans,(b[lst]+b[lst])*(c[lft]+c[rit]));
		}
	for (lst=1;lst<=w;lst++)
	   for (nxt=1;nxt<=w;nxt++){
	   	  lft=V[b[lst]][V[b[lst]].size()-1];rit=V[b[nxt]][V[b[nxt]].size()-1];
	   	  if (check(lft,rit))
	   	     ans=max(ans,(b[lst]+b[nxt])*(c[lft]+c[rit]));
	   }
	printf("%lld\n",ans);
	for (i=1;i<=w;i++)
	   for (j=0;j<V[i].size();j++)
	         tag[V[i][j]]=0;
	for (i=1;i<=m;i++) exist[make_pair(la[i],lb[i])]=0,exist[make_pair(lb[i],la[i])]=0;
	for (i=1;i<=n;i++) E[i].clear();
	for (i=1;i<=n;i++) V[i].clear();
	for (i=1;i<=n;i++) fre[a[i]]--;
}
int main() {
	int Testing=read();
	for (;Testing;Testing--) Main();
	return 0;
}