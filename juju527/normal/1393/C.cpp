#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;
int t[maxn],a[maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
priority_queue<int>q;
int c[maxn];
bool check(int k){
	while(!q.empty())q.pop();
	for(int i=1;i<=n;i++)if(t[i])q.push(t[i]);
	for(int i=1;i<=n;i++){
		if(q.empty())return 0;
		int tot=q.top();
		q.pop();
		c[i]=tot;
		if(i>k&&c[i-k]>1)q.push(c[i-k]-1);
	}
	if(!q.empty())return 0;
	return 1;
}
int main(){
	int T;
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)t[i]=0;
		for(int i=1;i<=n;i++)t[read()]++;
		int l=0,r=n-1;
		while(l+1<r){
			int mid=l+((r-l)>>1);
			if(check(mid))
				l=mid;
			else
				r=mid;
		}
		printf("%d\n",l);
	}
	return 0;
}