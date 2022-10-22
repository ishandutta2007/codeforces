#include<bits/stdc++.h>
#define ll long long
using namespace std;
void work(){
	ll a,b,c,d;
	cin>>a>>b>>c>>d;
	a*=d;
	c*=b;
	if(a==c)puts("0");
	else if(a==0||c==0||a%c==0||c%a==0)puts("1");
	else puts("2");
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}