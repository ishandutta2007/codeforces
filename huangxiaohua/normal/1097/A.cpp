#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[666];
string sb;
int main() {
	cin>>sb;
	a[sb[0]]=1;
	a[sb[1]]=1;
	for(i=1;i<=5;i++){
		cin>>sb;
		if(a[sb[0]]||a[sb[1]]){cout<<"YES";return 0;
		}
	}
	cout<<"NO";
}