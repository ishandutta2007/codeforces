#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define LL long long
#define N 500050
using namespace std;
int n,cnt=0;
LL a[N];
int q[N];
double ans=0,re;
double slope(int x,int y){
	return (double)((double)(x+1)*(double)a[y]-(double)(y+1)*(double)a[x])/(double)(y-x);
}
int main(){
	int op,l=1,r=0;LL x;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&op);
		if(op==1){
			if(cnt>0){
				while(r>1&&slope(q[r-1],q[r])>=slope(q[r],cnt)) r--;
				q[++r]=cnt;
			}
			scanf("%I64d",&x);
			cnt++;a[cnt]=a[cnt-1]+x;
			while(l<r&&slope(q[l],q[l+1])<(double)x) l++;
			re=double((double)x-(double)(a[q[l]]+x)/(double)(q[l]+1));
			if(re>ans) ans=re;
		}
		else{
			printf("%0.10lf\n",ans);
		}
	}
	return 0;
}