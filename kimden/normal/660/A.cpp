#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int x,int y){
	if(x==0) return y;
	if(y==0) return x;
	if(x%y==0) return y;
	if(y%x==0) return x;
	if(x>y) return gcd(y,x%y);
	if(y>x) return gcd(x,y%x);
	return x;
}
int main()
{
	int n;
	cin >> n;
	int a[1005];
	bool b[1005]={};
	int ans = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(i>0 && gcd(a[i-1],a[i])>1){
			b[i-1]=true;
			ans++;
		}
	}
	cout << ans << "\n";
	for(int i=0;i<n;i++){
		if(i!=0){
			cout << " ";
		}
		cout << a[i];
		if(b[i]){
			cout << " 1";
		}
	}
}