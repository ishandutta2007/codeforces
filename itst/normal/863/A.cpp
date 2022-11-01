#include<bits/stdc++.h>
using namespace std;
int main(){
	string n;
	cin >> n;
	int i = n.size() - 1;
	while(n[i] == '0')	i--;
	for(int j = 0 ; j <= i / 2 ; j++)
		if(n[j] != n[i - j])
		{
			cout << "NO";
			return 0;
		}
	cout << "YES";
	return 0;
}