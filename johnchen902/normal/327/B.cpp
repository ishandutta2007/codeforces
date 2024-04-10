#include <iostream>

const int SIZE = 1300000;
const int SQRT = 1150;

using namespace std;

bool isNotPrime[SIZE / 2]; // 0 = 3, 1 = 5, 2 = 7 ...
inline bool& isnp(int i){
	return isNotPrime[(i>>1) - 1];
}
void findFirst(int n){
	cout << 2;
	n--;
	if(n == 0)
		return;
	for(int i = 3; i <= SQRT; i += 2)
		if(!isnp(i)){
			cout << " " << i;
			n--;
			if(n == 0)
				return;
			for(int j = i * i; j <= SIZE; j += i << 1)
				isnp(j) = true;	
		}
	for(int i = SQRT + 1; i <= SIZE; i += 2){
		if(!isnp(i)){
			cout << " " << i;
			n--;
			if(n == 0)
				return;
		}
	}
	// impossible
}
int main(){
	int n;
	cin >> n;
	findFirst(n);
	cout << endl;
	return 0;
}