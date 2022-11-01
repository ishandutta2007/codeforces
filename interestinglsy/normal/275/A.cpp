#include <iostream>
#define uint unsigned int
using namespace std;

bool light[5][5];

int main(){
	for(uint i = 1;i <= 3;i++){
		for(uint j = 1;j <= 3;j++){
			uint d;
			cin >> d;
			if(d & 1){
				light[i][j] ^= 1;
				light[i-1][j] ^= 1;
				light[i+1][j] ^= 1;
				light[i][j-1] ^= 1;
				light[i][j+1] ^= 1;
			}
		}
	}
	for(uint i = 1;i <= 3;i++){
		for(uint j = 1;j <= 3;j++)
			cout << (light[i][j]==0?1:0);
		cout << endl;
	}
	return 0;
}