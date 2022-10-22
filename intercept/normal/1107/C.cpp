#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int read(){
	int rex=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){rex=rex*10+ch-'0';ch=getchar();}
	return rex*f;
}
int n,k;
long long ans=0;
int a[200009];
char c[200009];
priority_queue<int>q;
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i)a[i]=read();
	scanf("%s",c+1);
	c[n+1]='#';
	for(int i=1;i<=n+1;++i){
		if(c[i]==c[i-1]||i==1){
			q.push(a[i]);
		}
		else {
			int s=k;
			while(s--&&!q.empty()){
				ans+=q.top();
				q.pop();
			}
			while(!q.empty())q.pop();
			q.push(a[i]);
		}
	}
	printf("%lld",ans);
	return 0;
}