#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
ll n;
int main(){
	cin>>n;
	f(i,n,2000){
		int c=i,sum=0;
		while(c>0){
			sum+=c%10;
			c/=10;
		}
		if(sum%4==0){cout<<i;return 0;}
	}
}