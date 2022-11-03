#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,h;
	int a,ans=0;
	cin >> n >> h;
	for(int i=0;i<n;i++){
		cin >> a;
		if(a>h){
			ans++;
		}
		ans++;
	}
	cout << ans;
	return 0;
}