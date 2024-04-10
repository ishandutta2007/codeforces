#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[4];
int main(){
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if ((a[0]&1)==(a[1]&1)) cout<<a[1]<<endl;
	else cout<<a[2]<<endl;
	return 0;
}