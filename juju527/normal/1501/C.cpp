#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,maxw=5e6+5;
struct node{
	int id,data;
	bool operator <(node i)const{
		return data<i.data;
	}
}a[maxn];
int t[maxw];
struct pa{
	int x,y;
};
pa s[maxw];
bool vis[maxw];
int p[maxw];
bool ban[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
   	int n,w;
	n=read();
	int two=0,pre=0,pos=0;
	for(int i=1;i<=n;i++)a[i]=(node){i,read()};
	sort(a+1,a+n+1);
	bool tag=0;
	for(int i=1;i<=n;i++){
		t[a[i].data]++;
		p[a[i].data]=i;
		if(t[a[i].data]==2){
			two++;
			if(two==2){
				puts("YES");
				printf("%d %d %d %d\n",a[pre].id,a[i].id,a[pre-1].id,a[i-1].id);
				return 0;
			}
			pre=i;
			pos=i;
		}
		if(t[a[i].data]==4){
			puts("YES");
			printf("%d %d %d %d\n",a[i].id,a[i-1].id,a[i-2].id,a[i-3].id);
			return 0;
		}
		if(t[a[i].data]==3)pos=i,tag=1;
	}
	w=a[n].data;
	for(int i=1;i<=w;i++){
		if(a[i].data==a[pos].data)break;
		if(t[2*a[pos].data-a[i].data]){
			puts("YES");
			printf("%d %d %d %d\n",a[pos].id,a[pos-1].id,a[i].id,a[p[2*a[pos].data-a[i].data]].id);
			return 0;
		}
	}
	if(pos){
		ban[pos]=1;
		if(tag)ban[pos-1]=1;
	}
	for(int i=1;i<=n;i++){
		if(ban[i])continue;
		for(int j=i+1;j<=n;j++){
			if(ban[j])continue;
			int val=a[i].data+a[j].data;
			if(vis[val]){
				puts("YES");
				printf("%d %d %d %d\n",a[i].id,a[j].id,s[val].x,s[val].y);
				return 0;
			}
			vis[val]=1;
			s[val]=(pa){a[i].id,a[j].id};
		}
	}
	puts("NO");
    return 0;
}