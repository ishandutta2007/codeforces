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

int n,a[N],b[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	if(a[1]!=b[1]||a[n]!=b[n]){printf("No");return 0;}
	for(int i=1;i<n;i++)a[i]=a[i+1]-a[i],b[i]=b[i+1]-b[i];
	sort(a+1,a+n),sort(b+1,b+n);
	for(int i=1;i<n;i++)if(a[i]!=b[i]){printf("No");return 0;}
	printf("Yes");
	return 0;
}