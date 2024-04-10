#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int vis[N],cnt,MAX=0,sum=0;
int line[N];
int a[N];
int l[N],r[N],kind[N];
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int main(){
	int n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=1;i<=n;i++){
		if(i==1||i==n)continue;
		if(a[i]>a[i+1]&&a[i]>a[i-1])vis[i]=1;//up
		if(a[i]<a[i+1]&&a[i]<a[i-1])vis[i]=2;//down
	}
	if(a[1]>a[2])vis[1]=1;
	else vis[1]=2;
	if(a[n]>a[n-1])vis[n]=1;
	else vis[n]=2;
	int pre=1;
	for(int i=2;i<=n;i++){
		if(vis[i]){
			int len=i-pre+1;
			line[++cnt]=len;
			l[cnt]=pre,r[cnt]=i;
			MAX=max(MAX,line[cnt]);
			pre=i;
		}
	}
	for(int i=1;i<=cnt;i++){
		if(line[i]==MAX){
			if(line[i]!=line[i-1]&&sum!=0){
				puts("0");return 0;
			}
			if(sum>=2){
				puts("0");return 0;
			}
			if(a[r[i]]>a[l[i]]&&sum==1){
				puts("0");return 0;
			}
		}
		if(line[i]==MAX)sum++;
	}
	for(int i=1;i<=cnt;i++){
		if(line[i]==MAX){
			int L=l[i],R=r[i],flag,x,lennow=0,lenpre=0;
			lennow=line[i];
			if(a[R]>a[L])flag=1;//up
			else flag=2;//down
			if(i==1&&flag==2||i==cnt&&flag==1){puts("0");return 0;}
			if(flag==1)lenpre=line[i+1];
			else lenpre=line[i-1];
			int xx=lenpre,yy=lennow/2*2;
			if(xx>yy){
				puts("1");return 0;
			}
			puts("0");return 0;
		}
	}
	return 0;
}