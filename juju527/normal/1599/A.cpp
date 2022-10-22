#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=400010;
int i,j,k,n,m,T,a[maxn],l=200005,r=200005,vis[maxn];
string s;
int Q[maxn],top;
int main(){
	cin>>n;
	for(i=1;i<=n;i++)a[i]=read();
	cin>>s;
	sort(a+1,a+1+n);
	if(s[0]=='L')vis[l]=1;
	else vis[l]=2;
	Q[++top]=l;
	for(i=2;i<=n;i++){
		if(vis[l]==1 && vis[r]==1){
			if(s[i-1]=='R')vis[++r]=2,Q[++top]=r;
			else vis[--l]=2,Q[++top]=l;
		}else
		if(vis[l]==2 && vis[r]==1){
			if(s[i-1]=='R')vis[++r]=2,Q[++top]=r;
			else vis[--l]=1,Q[++top]=l;
		}else
		if(vis[l]==1 && vis[r]==2){
			if(s[i-1]=='R')vis[--l]=2,Q[++top]=l;
			else vis[++r]=1,Q[++top]=r;
		}else
		if(vis[l]==2 && vis[r]==2){
			if(s[i-1]=='R')vis[--l]=1,Q[++top]=l;
			else vis[++r]=1,Q[++top]=r;
		}
	}
	for(i=1;i<=top;i++){
		int now=Q[i];
		printf("%d %c\n",a[Q[i]-l+1],vis[now]==1?'L':'R');
	}
}