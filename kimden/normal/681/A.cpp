#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	string s;
	int a,b;
	cin >> n;
	bool ans=false;
	for(int i=0;i<n;i++){
		cin >> s >> a >> b;
		if(a>=2400 && b>a){
			ans = true;
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}