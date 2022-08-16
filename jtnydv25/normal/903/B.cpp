#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int main(){
	int h1, a1, c1;
	int h2, a2;
	cin >> h1 >> a1 >> c1 >> h2 >> a2;
	int mnPhases = (h2 - 1) / a1 + 1;
	int attackB = mnPhases - 1;
	int minHealth = attackB * a2 + 1;
	int k = (minHealth <= h1) ? 0 : (minHealth - h1 - 1) / (c1 - a2) + 1;
	cout << k + mnPhases << endl;
	for(int i = 1; i <= k; i++) cout << "HEAL" << endl;
	for(int i = 1; i <= mnPhases; i++) cout << "STRIKE" << endl;
}