#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int n, a[2009], b[3][2009] ,c[2009], z = 0;
int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
	{		cin >> a[i]; c[i] = i;
}
	for (int i = 0; i < n - 1; i++)
	for (int j = i + 1; j<n; j++)
	if (a[i] > a[j]) {
		int t = a[i]; a[i] = a[j]; a[j] = t;
		t = c[i]; c[i] = c[j]; c[j] = t;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
		if (i != j&&a[i] == a[j]) {
			int t = a[i]; a[i] = a[j]; a[j] = t;
			t = c[i]; c[i] = c[j]; c[j] = t;
			for (int o = 0; o < n; o++)
			{

				b[z][o] = c[o] + 1;

			}
			z++;
			if (z == 3) break;
		}
		if (z == 3) break;

	}

	if (z==3){	cout << "YES" << endl;
		for (int i = 0; i < 3; i++)
		{	for (int j = 0; j < n; j++)
			cout << b[i][j] << " ";
		cout << endl;
	}
	}
	else cout << "NO";

	return 0;

}