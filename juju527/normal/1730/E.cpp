// LUOGU_RID: 90163149
//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=5e5+5,maxw=1e6+5;
int a[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
vec d[maxw];
ll res;
int mx[maxn],mn[maxn];
int cnt[maxw];
void solve(int l,int r){
	if(l==r){res++;return ;}
	int mid=l+((r-l)>>1),it1,it2,lst=res;
	mx[mid]=mn[mid]=a[mid];
	for(int i=mid-1;i>=l;i--)mx[i]=max(mx[i+1],a[i]),mn[i]=min(mn[i+1],a[i]);
	mx[mid+1]=mn[mid+1]=a[mid+1];
	for(int i=mid+2;i<=r;i++)mx[i]=max(mx[i-1],a[i]),mn[i]=min(mn[i-1],a[i]);
	it1=it2=mid;
	for(int i=mid;i>=l;i--){
		while(it1<r&&mx[it1+1]<=mx[i])cnt[mn[++it1]]++;
		while(it2<it1&&mn[it2+1]>=mn[i])cnt[mn[++it2]]--;
		ll aux=0;
		for(auto v:d[mx[i]]){
			if(v>=mn[i])break;
			aux+=cnt[v];
		}
		if(mx[i]%mn[i]==0)aux+=it2-mid;
		res+=aux;
	}
	for(int i=it2+1;i<=it1;i++)cnt[mn[i]]--;
	it1=it2=mid+1;
	for(int i=mid+1;i<=r;i++){
		while(it1>l&&mx[it1-1]<mx[i])cnt[mn[--it1]]++;
		while(it2>it1&&mn[it2-1]>=mn[i])cnt[mn[--it2]]--;
		ll aux=0;
		for(auto v:d[mx[i]]){
			if(v>=mn[i])break;
			aux+=cnt[v];
		}
		if(mx[i]%mn[i]==0)aux+=mid+1-it2;
		res+=aux;
	}
	for(int i=it1;i<it2;i++)cnt[mn[i]]--;
	solve(l,mid),solve(mid+1,r);
	return ;
}
int main(){
    int T;
	T=read();
	for(int i=1;i<=1e6;i++)for(int j=i;j<=1e6;j+=i)d[j].eb(i);
	while(T--){
		int n;
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		res=0;solve(1,n);
		printf("%lld\n",res);
	}
    return 0;
}