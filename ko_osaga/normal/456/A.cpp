#include <cstdio>  
#include <cstdlib>  
#include <vector>  
#include <iostream>  
using namespace std;  

int t[100005];

int main(){
	int n;
	cin >> n;
	while(n--){
		int a, b;
		cin >> a >> b;
		if(a != b){
			puts("Happy Alex");
			return 0;
		}
	}
	puts("Poor Alex");
}