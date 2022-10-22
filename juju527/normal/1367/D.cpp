#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
int a[maxn];
int b[maxn],v[maxn],val[maxn],cur[maxn],tot[maxn];
int to[maxn];
queue<int>q;
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	int t;
	t=read();
	while(t--){
		int n,m,maxv=0;
		string s;
		cin>>s;
		n=s.size();
		for(int i=0;i<s.size();i++)a[i+1]=s[i]-'a';
		sort(a+1,a+n+1);
		m=read();
		memset(cur,0,sizeof(cur));
		for(int i=1;i<=m;i++){
			b[i]=read();
			if(b[i]==0){
				q.push(i);
				v[i]=1;
				cur[v[i]]++;
                maxv=1;
			}
		} 
		while(!q.empty()){
			int k=q.front();
			q.pop();
			for(int i=1;i<=m;i++){
				if(!b[i])continue;
				b[i]-=abs(k-i);
				if(!b[i]){
					q.push(i);
					v[i]=v[k]+1;
					cur[v[i]]++;
					maxv=max(maxv,v[i]);
				}
			}
		}
		memset(tot,0,sizeof(tot));
		int cnt=1;
		val[1]=a[n];tot[1]=1;
		for(int i=n-1;i>=1;i--){
			if(a[i]<a[i+1]){val[++cnt]=a[i];tot[cnt]=1;}
			else tot[cnt]++;
		}
		to[0]=0;
		for(int i=1;i<=maxv;i++)
			for(int j=to[i-1]+1;j<=cnt;j++)
				if(tot[j]>=cur[i]){to[i]=j;break;}
		for(int i=1;i<=m;i++)
			printf("%c",val[to[v[i]]]+'a');
		putchar('\n');
	}
	return 0;
}