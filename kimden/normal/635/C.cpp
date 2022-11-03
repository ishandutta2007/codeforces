#include <iostream>
#include <cstdio>
using namespace std;
typedef long long int ll;

int main()
{
	ll s,x,y,z,c;
	int i;
	ll ans=1;
	bool b=false;
	cin >> s >> x;
	if((s-x)%2!=0){
		cout << 0;
		return 0;
	}
	if(s==x){
		b=true;
	}
	z = ((s-x) >> 1);
	if((x & z)!=0){
		cout << 0;
		return 0;
	}
	while(x!=0){
		ans*=(x%2+1);
		x = x >> 1;
	}
	if(b)
		ans-=2;
	cout << ans;
	return 0;
}