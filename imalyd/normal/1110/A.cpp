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

int b,n,a[N],s;

int main(){
	scanf("%d%d",&b,&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(b&1){
	    for(int i=1;i<=n;i++)s=(s^a[i])&1;
	}else s=a[n]&1;
	if(s)printf("odd");else printf("even");
	return 0;
}