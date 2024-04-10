#include <iostream>
#include <string>

using namespace std;

int n , m , z;

int main(){
	cin >> n >> m;
	for (int i = 0; i <= n; i++ )
		for (int j = 0; j <=n; j++) 
			if (i + (j*j) == n &&  (i*i) + j == m)  z++;

	cout<<z;


}