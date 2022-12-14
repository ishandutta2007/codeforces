#include<bits/stdc++.h>
using namespace std;
#define py puts("Yes");
#define pn puts("No");
#define N 200005
int n,T,i,tot,x,ans[N],a[N],nxt[N],las[N];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
queue<int>q;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;++i){
			cin>>a[i];
		}
		for(i=1;i<n;++i){
			if(gcd(a[i],a[i+1])==1)q.push(i+1);
			nxt[i]=i+1;las[i+1]=i; 
		}tot=0;
		if(gcd(a[n],a[1])==1)q.push(1);nxt[n]=1;las[1]=n;
		while(q.size()){
			x=q.front();q.pop();
			nxt[las[x]]=nxt[x];
			las[nxt[x]]=las[x];
			ans[++tot]=x;
			if(q.size()&&q.front()==nxt[x]){
				if(gcd(a[las[x]],a[nxt[x]])==1)q.push(q.front());
				q.pop();
			}
			else if(las[x]!=nxt[x]&&gcd(a[las[x]],a[nxt[x]])==1)q.push(nxt[x]);
		}cout<<tot<<" ";
		for(i=1;i<=tot;++i)cout<<ans[i]<<" ";cout<<"\n";
	}
}