#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;

int main()
{
	cin >> c;
	for(a=1;a*a+a+1<c;++a){
		ll d=c-a*a-a-1;
		if(d%(a*2)==0){
			cout << a << " " << d/(2*a) << endl;
			return 0;
		}
	}
	puts("NO");
}