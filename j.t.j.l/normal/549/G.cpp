#include<iostream>
#include<cmath> 
#include<cstdio>
#include<algorithm>
#define N 200005
#define INF 0x4fffffff
#define PI 3.14159265358979323846
#define MM 1000000007

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)

using namespace std;

int i,n,flag,a[200005];

int main(){
	cin>>n;
	rep(i,1,n){
		scanf("%d",&a[i]);
		a[i]-=(n-i);
	}
	sort(a+1,a+n+1);
	rep(i,1,n)
		a[i]+=(n-i);
	flag=1;
	rep(i,1,n-1)
		if (a[i]>a[i+1]){
			flag=0;
			break;
		}
	if (flag){
		rep(i,1,n-1)
			printf("%d ",a[i]);
		printf("%d\n",a[i]);
	}
	else{
		printf(":(\n");
	}
	return 0;
}