#include <iostream>
using namespace std;
int main(){
	string s,c="Draw";
	int k=1,n=0;
	for (int i=0; i<8; i++){
		cin >> s;
		for (int j=0; j<8; j++){
			k=1;
			if (s[j]<'a'){
				s[j]+=32;
				k=-1;
			}
			if (s[j]=='q'){
				k*=9;
			}
			else if (s[j]=='r'){
				k*=5;
			}
			else if (s[j]=='b'){
				k*=3;
			}
			else if (s[j]=='n'){
				k*=3;
			}			
			else if (s[j]=='p'){
				k*=1;
			}
			else{
				k*=0;
			}
			n+=k;
		}
	}
	if (n>0){
		c="Black";
	}
	else if (n<0){
		c="White";
	}
	cout << c;
	return 0;
}