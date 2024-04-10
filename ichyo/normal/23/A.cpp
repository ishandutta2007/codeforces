#include <iostream>
#include <string>

using namespace std;

int main(void){
	int count=0;
	string string;
	cin >> string;
	for(int i=1;i<string.size();i++){
		bool f = false;
		for(int j=0;j<string.size()-i+1; j++){
			if(string.rfind(string.substr(j,i))!=j){
				count++;
				f = true;
				break;
			}
		}
		if(!f) break;
	}
	cout << count << endl;
	return 0;
}