#include<iostream>
#include<cmath> 
#include<cstring> 
#include<cstdio>
#include<algorithm>
#define N 120007
#define INF 2147483647
#define PI 3.14159265358979323846

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)

using namespace std;

int i,n;
int a[N],b[N],c[N];

int main(){
	cin>>n;
	rep(i,1,n)
		scanf("%d",&a[i]);
	rep(i,1,n-1)
		scanf("%d",&b[i]);
	rep(i,1,n-2)
		scanf("%d",&c[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+n);
	sort(c+1,c+n-1);
	b[n]=a[n]-1;
	c[n-1]=b[n-1]-1;
	rep(i,1,n)
		if (a[i]!=b[i]){
			cout<<a[i]<<endl;
			break;
		}
	rep(i,1,n-1)
		if (b[i]!=c[i]){
			cout<<b[i]<<endl;
			break;
		}
	return 0;
}