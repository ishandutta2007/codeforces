#include<bits/stdc++.h>
using namespace std;
int main(){
	int tarA , tarB;
	cin >> tarB >> tarA;
	if(tarB == 0 && tarA == 1)
		cout << "YES";
	else
		if(tarB == 0 || tarA == 1 || tarA == 0)
			cout << "NO";
		else
			if(tarB - tarA >= -1 && (tarB - tarA + 1) % 2 == 0)
				cout << "YES";
			else
				cout << "NO";
	return 0;
}