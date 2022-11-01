#include <iostream>
using namespace std;
int main(){
	int size;
	cin >> size;
	int sum = 0, partSum = 0, maxPartSum = 0;
	for(int i = 0; i < size; i++){
		bool in; // 1 or 0
		cin >> in;
		sum += in;
		partSum += in ? -1 : 1;
		if(partSum < 0)
			partSum = 0;
		else if(partSum > maxPartSum)
			maxPartSum = partSum;
	}
	if(maxPartSum == 0) // all is 1
		maxPartSum = -1; // must negate 1
	cout << sum + maxPartSum << endl;
	return 0;
}