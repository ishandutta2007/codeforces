#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll n,cnt,x;
int main(){
	cin>>n;
	for (ll i=2;i*i<=n;i++){
		if (n%i==0){
			cnt++;x=i;
			while (n%i==0)n/=i;
		}
	}
	if (n>1)cnt++,x=n;
	if (cnt==1){
		cout<<x<<endl;
	}
	else cout<<1<<endl;
}