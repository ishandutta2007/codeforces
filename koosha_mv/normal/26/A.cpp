#include <bits/stdc++.h>
#include<algorithm>
#define salamkhoobichwtori 1e17
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
int f1[3009],n,ans;
int main(){
	cin>>n;
	f(i,2,3004){
		if(f1[i]==0){
			for(int j=i*2;j<3004;j+=i){
				f1[j]++;
			}
		}
	}
	f(i,2,n+1){
		if(f1[i]==2)
			ans++;
	}
	cout<<ans;
}