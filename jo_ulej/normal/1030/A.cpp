#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int n, sum, temp;
	sum = 0;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> temp;
		sum += temp;
	}

	if(sum == 0)
		cout << "EASY" << endl;
	else
		cout << "HARD" << endl;

	return 0;
}