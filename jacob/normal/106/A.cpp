#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char cards[] = "23456789TJQKA";

int main(void) {
	string coz;
	string k1, k2;
	cin >> coz >> k1 >> k2;
	int n1 = find(cards, cards + strlen(cards), k1[0]) - cards;
	int n2 = find(cards, cards + strlen(cards), k2[0]) - cards;
	if ((k1[1] == coz[0] && k2[1] != coz[0]) || (n1 > n2 && k1[1] == k2[1]))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}