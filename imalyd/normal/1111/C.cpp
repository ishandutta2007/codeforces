#include<bits/stdc++.h>
using namespace std;
#define ll long long
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}

const int N=1000005;

int n,k,a[N];
ll A,B;
#define mid ((l+r)>>1)
ll solve(int l,int r){
	//printf("%d\n",upper_bound(a+1,a+k+1,r)-a);
	//printf("%d\n",lower_bound(a+1,a+k+1,l)-a);
	int s=upper_bound(a+1,a+k+1,r)-lower_bound(a+1,a+k+1,l);//printf("[%d,%d] %d\n",l,r,s);
	if(!s)return A;
	if(l==r)return B*s;
	return min(B*s*(r-l+1),solve(l,mid)+solve(mid+1,r));
}
int main(){
    n=rd(),k=rd(),A=rd(),B=rd();
	for(int i=1;i<=k;i++)a[i]=rd();sort(a+1,a+k+1);
	printf("%I64d",solve(1,1<<n));
    return 0;
}