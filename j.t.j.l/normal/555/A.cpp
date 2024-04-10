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

int n,m,k,i,j,tot,x,y;
int a[100005];

int main(){
	cin>>n>>k;
	tot=k-1;
	rep(i,1,k){
		cin>>m;
		tot=tot+2*(m-1);
		rep(j,1,m){
			scanf("%d",&a[j]);
		}
		sort(a+1,a+m+1);
		if (a[1]==1){
			j=2;
			while((j<=m)&&(a[j]==j)){
				tot-=2;
				j++;
			}
		}
	}
	printf("%d\n",tot);
	return 0;
}