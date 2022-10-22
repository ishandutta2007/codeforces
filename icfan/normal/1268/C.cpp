#include <cstdio>
#include <iostream>
using namespace std;
#define Maxn 200000
#define ll long long
int n;
int a[Maxn+5];
int p[Maxn+5];
int f_1[Maxn+5];
ll f_2[Maxn+5];
void add_1(int x,int a){
	for(int i=x;i<=n;i+=(i&(-i))){
		f_1[i]+=a;
	}
}
void add_2(int x,int a){
	for(int i=x;i<=n;i+=(i&(-i))){
		f_2[i]+=a;
	}
}
int query_1(int x){
	int ans=0;
	for(int i=x;i>0;i-=(i&(-i))){
		ans+=f_1[i];
	}
	return ans;
}
ll query_2(int x){
	ll ans=0;
	for(int i=x;i>0;i-=(i&(-i))){
		ans+=f_2[i];
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[a[i]]=i;
	}
	ll ans=0,tmp=0,sum=0;
	int now;
	for(int i=1;i<=n;i++){
		ans+=(i-1)-query_1(p[i]);
		add_1(p[i],1);
		add_2(p[i],p[i]);
		tmp+=p[i];
		int left=1,right=n,mid;
		while(left<right){
			mid=(left+right+1)>>1;
			now=query_1(mid);
			if(now*2>i){
				right=mid-1;
			}
			else{
				left=mid;
			}
		}
		now=query_1(left);
		ll now_2=query_2(left);
		ll now_3=tmp-now_2;
		sum=1ll*left*now-now_2-1ll*now*(now-1)/2+now_3-1ll*left*(i-now)-1ll*(i-now+1)*(i-now)/2;
		cout<<ans+sum<<' ';
	}
	puts("");
	return 0;
}
/*
10
10 1 8 3 6 5 4 7 2 9
1:10 1 8 3 6 5 4 7 2 9 ------- 0      ~~~~~~~~~~ +0
2:10 1 2 8 3 6 5 4 7 9 ------- 6      ~~~~~~~~~~ +6
3:10 1 2 3 8 6 5 4 7 9 ------- 7      ~~~~~~~~~~ +1
4:10 1 2 3 4 8 6 5 7 9 ------- 10     ~~~~~~~~~~ +3
5:10 1 2 3 4 5 8 6 7 9 ------- 12     ~~~~~~~~~~ +2
6:10 1 2 3 4 5 6 8 7 9 ------- 13     ~~~~~~~~~~ +1
7:10 1 2 3 4 5 6 7 8 9 ------- 14     ~~~~~~~~~~ +1
8:10 1 2 3 4 5 6 7 8 9 ------- 14     ~~~~~~~~~~ +0
9:10 1 2 3 4 5 6 7 8 9 ------- 14     ~~~~~~~~~~ +0
10:1 2 3 4 5 6 7 8 9 10 ------ 23     ~~~~~~~~~~ +6
*/