#include <iostream>
#include <cstdio>
#define B cout << "Breakpoint!\n";
using namespace std;

int n;
int num[200005];

int main(){
//	freopen("inp.txt","r",stdin);
	
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> num[i];
		
	for(int i = 1;i <= n/2;i += 2)
		swap(num[i],num[n-i+1]);
	
	for(int i = 1;i <= n;i++)
		cout << num[i] << " ";
	
	return 0;
}