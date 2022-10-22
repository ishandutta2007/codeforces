//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
typedef double db;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
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
const int maxn=1e5+5;
struct node{
	int x,t;
	bool operator <(node i)const{return x<i.x;}
}a[maxn];
multiset<int>s1,s2;
int main(){
    int T;
	T=read();
	while(T--){
		int n;
		n=read();
		for(int i=1;i<=n;i++)a[i].x=read();
		for(int i=1;i<=n;i++)a[i].t=read();
		if(n==1){printf("%d\n",a[1].x);continue;}
		sort(a+1,a+n+1);
		s1.clear();s2.clear();
		for(int i=2;i<=n;i++)s1.insert(a[i].x+a[i].t);
		s2.insert(a[1].t-a[1].x);
		db res=1e9,x0=0;
		for(int i=1;i<n;i++){
			db v1=*s1.rbegin(),v2=*s2.rbegin();
			db p=(v1-v2)/2.0;
			if(p>=a[i].x&&p<=a[i+1].x){if(res>v1-p)res=v1-p,x0=p;}
			else if(p<a[i].x){if(res>max(v1-a[i].x,v2+a[i].x))res=max(v1-a[i].x,v2+a[i].x),x0=a[i].x;}
			else{if(res>max(v1-a[i+1].x,v2+a[i+1].x))res=max(v1-a[i+1].x,v2+a[i+1].x),x0=a[i+1].x;}
			s1.erase(s1.find(a[i+1].x+a[i+1].t));s2.insert(a[i+1].t-a[i+1].x);
		}
		printf("%.6lf\n",x0);
	}
    return 0;
}