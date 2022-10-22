//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
const int maxn=2048+5;
inline int query(int x,int y){
	printf("? %d %d\n",x,y);fflush(stdout);
	return read();
}
int x[maxn],p[maxn];
mt19937 rnd(time(0));
int main(){
    int n;
	n=read();
	for(int i=1;i<=n;i++)x[i]=i;
	shuffle(x+1,x+n+1,rnd);
	int a=x[1],b=x[2],v=query(a,b);
	for(int i=3;i<=n;i++){
		int c=x[i],w=query(a,c);
		if(w<v)b=c,v=w;
		else if(w==v)a=c,v=query(b,c);
	}
	while(1){
		int z=rnd()%n+1;
		while(z==a||z==b)z=rnd()%n+1;
		int v1=query(a,z),v2=query(b,z);
		if(v1<v2)break;
		if(v1>v2){swap(a,b);break;}
	}
	for(int i=1;i<=n;i++){
		if(i==a)continue;
		p[i]=query(a,i);
	}
	printf("! ");
	for(int i=1;i<=n;i++)printf("%d ",p[i]);
	puts("");fflush(stdout);
    return 0;
}