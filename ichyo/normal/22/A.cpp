#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
int main(){
	int i;
	int n;
	int num[101];
	while(cin >> n){
		int flag=0;
		for (i=0; i < n; i++){
			cin >> num[i];
		}
		sort(num, num+n);
		for(i=0;i<n;i++){
			if(num[i] != num[0]) {
				flag = 1;
				break;
			}
		}
		if(flag) cout << num[i] << endl;
		else cout << "NO" << endl;
	}
	
	return(0);
}