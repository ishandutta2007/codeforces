#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
	int a , b , c;
	scanf ( "%d%d%d" , &a , &b , &c );
	printf ( "%d\n" , (b+c+a*1000) % a == 0 ? a : (b+c+a*1000) % a );
	return 0;
}