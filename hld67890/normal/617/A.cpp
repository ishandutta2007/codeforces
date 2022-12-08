#include <iostream>
#include <stdio.h>

using namespace std;

int main () {
	int a;
	scanf ( "%d" , &a );
	printf ( "%d\n" , (a/5)+(a%5!=0) );
	return 0;
}