#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int n,m;
long long f(int x){
	if(x%2==0){
		return 1ll*x*x/2;
	}else{
		return 1ll*x*(x-1)/2+1;
	}
}
int s[100005];
int main()
{
	scanf("%d%d",&n,&m);
	int l=1,r=50000,mid;
	while(l<=r){
		mid=l+r>>1;
		if(f(mid)>n)r=mid-1;
		else l=mid+1;
	}
	int ok=r;
	ok=min(m,ok);
	for (int i=1;i<=m;i++){
		int tmp;scanf("%d%d",&tmp,&s[i]);
	}
	sort(s+1,s+1+m);
	long long su=0;
	for (int i=m;i>=m-ok+1;i--)su+=s[i];
	cout<<su<<endl;
	return 0;
}