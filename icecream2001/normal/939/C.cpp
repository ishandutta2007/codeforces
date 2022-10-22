#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define LL long long
#define N 200050
using namespace std;
int n,k,sum=0,ans=1,r=0,t,T;
int a[N],s,f;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    	scanf("%d",&a[i]);
    	a[i+n]=a[i];
	}
	scanf("%d%d",&s,&f);
	k=f-s;
	for(int i=1;i<=n+k-1;i++){
		if(i<k){
			sum=sum+a[i];
		}
		else{
			sum=sum+a[i]-a[i-k];
			if(sum>r){
				ans=i-k+1;r=sum;
				t=s-ans+1;
				while(t<=0) t+=n;
				while(t>n) t-=n;
			}
			else if(sum==r){
				T=s-(i-k+1)+1;
				while(T<=0) T+=n;
				while(T>n) T-=n;
				if(T<t){
					t=T;ans=i-k+1;
				}
			}
		}
	}
	printf("%d\n",t);
	return 0;
}