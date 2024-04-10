#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
struct node{
	int s,a;
	bool operator <(node i)const{return (max(s,a)==max(i.s,i.a))?s<i.s:max(s,a)<max(i.s,i.a);}
}p[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
priority_queue<int> q;
int main(){
//    freopen("CF1601D.in","r",stdin);
//    freopen("CF1601D.out","w",stdout);
    int n,d;
	n=read();d=read();
	for(int i=1;i<=n;i++){
		int s,a;
		s=read();a=read();
		p[i]=(node){s,a};
	}
	sort(p+1,p+n+1);
	int res=0;
	for(int i=1;i<=n;i++){
		if(p[i].s>=d){
			d=max(d,p[i].a);
			res++;
		}
	}
	printf("%d\n",res);
    return 0;
}