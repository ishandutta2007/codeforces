#include <iostream>
using namespace std;
int main(){
	int n,a=0,b=0,m;
	cin >> n;
	while (n--){
		cin >> m;
		if (m==25){
			a++;
		}
		else if(m==50){
			b++;
			if (a!=0){
				a--;
			}
			else{
				cout << "NO";
				return 0;
			}
		}
		else{
			if (a>0 && b>0){
				a--;
				b--;
			}
			else if(a>2){
				a-=3;
			}
			else{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
	return 0;
}