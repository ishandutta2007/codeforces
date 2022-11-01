#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

int n,m,z;
int ans = 0;
bool data[30000];

int main(){
	memset(data,0,sizeof(data));

	cin >> n >> m >> z;
	
	for(int i = 1;i*m <= z;i++){
		data[i*m] = 1;
	}
	
	for(int i = 1;i*n <= z;i++){
		if(data[i*n])
			ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}