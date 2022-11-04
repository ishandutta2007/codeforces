#include<bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<(2*(b+d)+2*max(a,c)+4)<<"\n";
	return 0;
}