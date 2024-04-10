#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n , a , b , z;

int main(){
    cin >> n >> a >> b;
    for (int i = a+1; i <= n; i++ )
    	if	(n-i <= b) z++;
	cout<<z;
	return 0;
}