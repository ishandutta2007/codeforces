#include <iostream>
using namespace std;

int main()
{
	long long a,b,c;
	cin >>a>>b>>c;
	if (a<b) swap(a,b);
	if (a<c) swap(a,c);
	cout << (a>=2*(b+c)?b+c:(a+b+c)/3); 
	return 0;
}