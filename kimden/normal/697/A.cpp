#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
	int t,s,x;
	cin >> t >> s >> x;
	if(x<t || (x==t+1 && s>1) || (x-t)%s>=2){
		cout << "NO";
	}else{
		cout << "YES";
	}
}