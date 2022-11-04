#include<bits/stdc++.h>
using namespace std;

#define xx first
#define yy second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

int main() {
	int q;
	cin>>q;
	while(q--) {
		int a,b;
		cin>>a>>b;
		int sum=0;
		while(a<=b && a%2!=0) {
			sum+=(a&1?-a:a);
			a++;
		}
		while(a<=b && b%2!=1) {
			sum+=(b&1?-b:b);
			b--;
		}
		
		if(a<b) {
			sum+=(b-a+1)/2*(-1);
		}
		cout<<sum<<"\n";
	}
	return 0;
}