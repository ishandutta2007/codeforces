#include <iostream>
using namespace std;

int mina, maxa, minb, maxb, minc, maxc;

int main() {

	int n;
	cin >> n;
	cin >> mina >> maxa >> minb >> maxb >> minc >> maxc;
	int mini = minc + minb;
	int maxi = maxc + maxb;
	cout << min( n-mini, maxa ) << " ";
	n -= min( n-mini, maxa );
	cout << min( n-minc, maxb );
	n -= min( n-minc, maxb );
	cout << " " << n;
	return 0;
}