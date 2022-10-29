#include<bits/stdc++.h>

using namespace std;

int main(){
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	int p = max(3 * a / 10, a - a / 250 * c), q = max(3 * b/ 10, b - b / 250 * d);
	if (p < q)
		puts("Vasya");
	else
		if (p == q)
			puts("Tie");
		else
			puts("Misha");
	return 0;
}