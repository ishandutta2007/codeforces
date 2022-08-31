#include <cstdio>
#include <iostream>
using namespace std;

long long n,k;
int main(){
	cin>>n>>k;
	cout<<((n*2+k-1)/k)+((n*5+k-1)/k)+((n*8+k-1)/k);
}