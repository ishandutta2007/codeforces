#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1000010;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int used[N];
int sum[N];
inline void add(int x){
	while(x<N){
		sum[x]++;
		x+=lowbit(x); 
	}return;
}
inline int get(int x){
	int res=0;
	while(x){
		res+=sum[x];
		x-=lowbit(x);
	}return res;
}
signed main(){
	memset(used,-1,sizeof used);
	int n=read(),t=read();
	while(t--){
		int k=read();
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			int res=0;
			if(used[mid]!=-1)res=used[mid]+get(mid);
			else{
				printf("? %d %d\n",1,mid);
				fflush(stdout);
				res=read();used[mid]=res-get(mid);
			}
			if(mid-res>=k)r=mid-1;
			else l=mid+1;
		}
		printf("! %d\n",r+1);add(r+1);
				fflush(stdout);
		
	}
	return 0;
}