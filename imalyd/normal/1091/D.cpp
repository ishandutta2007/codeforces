//Problem D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000005;
const ll p=998244353;
ll n,a[N],s=1;
#define add(a,b) (((a)+(b)  )%p)
#define sub(a,b) (((a)-(b)+p)%p)
#define mul(a,b) (((a)*(b)  )%p)
int main(){
    cin>>n;a[0]=1;
	for(ll i=1;i<=n;i++)a[i]=mul(a[i-1],n-i+1);
	for(ll i=1;i<=n;i++)s=add(s,mul(i,sub(a[i],a[i-1])));
	cout<<s;
	return 0;
}