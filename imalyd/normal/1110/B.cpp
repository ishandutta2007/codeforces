#include<bits/stdc++.h>
using namespace std;
#define ll long long
int rd(){
    int a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}
ll rdll(){
    ll a=0;char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
    return a;
}

const int N=100005;

int n,m,k,a[N],b[N];
ll s;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);k=n-k;
	for(int i=1;i< n;i++)a[i]=b[i+1]-b[i]-1;sort(a+1,a+n);
	for(int i=1;i<=k;i++)s+=a[i];
	printf("%I64d",s+n);
	return 0;
}