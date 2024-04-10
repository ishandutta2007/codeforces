#include <bits/stdc++.h>
#define ll long long
#define N pair<int,int>
#define val first
#define pos second
using namespace std;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
const int maxn=1005,maxa=400005;
int len,res[maxa][2];
N x[maxn],tmp[5];
void move(N &a,N &b){
	len++;res[len][0]=a.pos,res[len][1]=b.pos;
	b.val-=a.val,a.val<<=1;
	return ;
}
void Sort(N &a,N &b,N &c){
	tmp[0]=a,tmp[1]=b,tmp[2]=c;
	sort(tmp,tmp+3);
	a=tmp[0],b=tmp[1],c=tmp[2];
	return ;
}
void work(N &a,N &b,N &c){
	Sort(a,b,c);
	if(!a.val)return ;
	int k=b.val/a.val;
	while(k){
		if(k&1)move(a,b);
		else move(a,c);
		k>>=1;
	}
	work(a,b,c);
	return ;
}
int main(){
	int n;
	n=read();
	for(int i=1;i<=n;i++)x[i]=make_pair(read(),i);
	int num=0;
	for(int i=1;i<=n;i++)if(x[i].val)num++;
	if(num<2){puts("-1");return 0;}
	for(int i=3;i<=n;i++)work(x[i-2],x[i-1],x[i]);
	printf("%d\n",len);
	for(int i=1;i<=len;i++)printf("%d %d\n",res[i][0],res[i][1]);
	return 0;
}