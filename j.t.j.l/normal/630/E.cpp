#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	cout<<(y2 - y1 + 1) / 2 * ((x2 - x1) / 2 * 2 + 1) + (y2 - y1 + 1) % 2 * ((x2 - x1) / 2 + 1) << endl;
	return 0;
}