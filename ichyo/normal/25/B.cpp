#include <iostream>
using namespace std;
int main(void){
	int n;
	char str[101];
	cin >> n;
	cin >> str;
	putchar(str[0]);
	putchar(str[1]);
	for(int i=2; i<n-1; i+=2){
		putchar('-');
		putchar(str[i]);
		putchar(str[i+1]);
	}
	if(n%2){
		putchar(str[n-1]);
	}
	return 0;
}