#include <bits/stdc++.h>
#define yes   cout << "YES"
#define no   cout << "NO"
#define ll long long 
using namespace std;

int main() {
	bool flag =true;
	ll n,m,k,h,ans=0;
	string s,s1;
	cin >>n;
	int a[10]={0};
	for(int i=0;i<n;i++){
		cin  >> k;
		a[k]++;
	}
	ans+=a[4];
	ans+=a[3];
	a[1]-=a[3];
	if (a[1]<0){
		a[1]=0;
	}
	ans+=a[2]/2;
	if (a[2]%2==1){
		a[1]+=2;
	}
	ans+=(a[1]+3)/4;
	cout << ans;
	return 0;
}