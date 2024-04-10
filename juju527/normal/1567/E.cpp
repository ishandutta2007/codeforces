#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int n,q;
int a[maxn];
set<int> st;
set<int>::iterator it,pre;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
ll f(int x){return 1ll*(x+1)*x/2;}
int lowbit[maxn];
ll t[maxn];
void update(int x,ll v){
	if(!x)return ;
	while(x<=n)t[x]+=v,x+=lowbit[x];
	return ;
}
ll query(int x){
	ll res=0;
	while(x)res+=t[x],x-=lowbit[x];
	return res;
}
int bl(int x){
	it=st.upper_bound(x);it--;
	return *it;
}
void ins(int x){
	if(st.find(x)!=st.end())return ;
	it=st.upper_bound(x);
	update(x,f((*it)-x));
	pre=it;it--;
	update(*it,f(x-(*it))-f((*pre)-(*it)));
	st.insert(x);
	return ;
}
void del(int x){
	if(st.find(x)==st.end())return ;
	it=st.upper_bound(x);
	update(x,-f((*it)-x));
	pre=it;it--;it--;
	update(*it,f((*pre)-(*it))-f(x-(*it)));
	st.erase(x);
	return ;
}
int main(){
	n=read();q=read();
	a[0]=1e9+1;a[n+1]=0;
	for(int i=1;i<=n;i++){
		lowbit[i]=i&-i;
		a[i]=read();
		if(a[i]<a[i-1])st.insert(i);
	}
	st.insert(0);st.insert(n+1);
	for(int i=1;i<=n;i++)if(a[i]<a[i-1])update(i,f((*st.upper_bound(i))-i));
	for(int i=1;i<=q;i++){
		int op,x,y;
		op=read();x=read();y=read();
		if(op==1){
			a[x]=y;
			if(a[x]<a[x-1])ins(x);else del(x);
			if(a[x]>a[x+1])ins(x+1);else del(x+1);
		}
		else{
			if(bl(x)==bl(y)){printf("%lld\n",f(y-x+1));continue;}
			it=st.upper_bound(y);it--;
			int l=*st.lower_bound(x),r=*it;
			ll res=query(r-1)-query(l-1);
			res+=f(l-x)+f(y-r+1);
			printf("%lld\n",res);
		}
	}
	return 0;
}