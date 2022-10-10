#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
typedef pair<int,int> pii;
const int maxn=1000010;
int i,j,k,n,m,T,a[maxn],chs[maxn],x;
priority_queue<pii>Q;
int main(){
	cin>>T;
	while(T--){
		while(!Q.empty())Q.pop();
		cin>>n>>m>>x;
		for(i=1;i<=n;i++)a[i]=read();
		for(i=1;i<=m;i++)Q.push(make_pair(-a[i],i)),chs[i]=i;
		for(i=m+1;i<=n;i++){
			int now=Q.top().second,S=-Q.top().first;Q.pop();
			S+=a[i];chs[i]=now;
			Q.push(make_pair(-S,now));
		}
		puts("YES");
		for(i=1;i<=n;i++)printf("%d ",chs[i]);puts("");
	}
	return 0;
}