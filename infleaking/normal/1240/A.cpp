#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll A[N],n,T,q[N],a,b,a1,b1,K;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
int main(){
	for (cin>>T;T--;){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%lld",&A[i]),A[i]/=100;
		sort(A+1,A+n+1);
		reverse(A+1,A+n+1);
		for (int i=1;i<=n;i++)q[i]=q[i-1]+A[i];
		int c1=0,c2=0,c3=0;
		int ans=-1;
		cin>>a1>>a>>b1>>b;
		if (a1<b1)swap(a,b),swap(a1,b1);
		cin>>K;
		for (int i=1;i<=n;i++){
			if (i%a==0)c1++;
			if (i%b==0)c2++;
			if (i%a==0&&i%b==0)c1--,c2--,c3++;
			ll sum=q[c3]*(a1+b1)+(q[c3+c1]-q[c3])*a1+(q[c1+c2+c3]-q[c3+c1])*b1;
			if (sum>=K){
				ans=i;
				break;
			}
		}
		cout<<ans<<endl;
	}
}