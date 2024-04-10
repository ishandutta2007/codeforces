#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,f,x,y,a[2][2]={0};
	cin >> n;
	while (n--){
		cin >> f >> x >> y;
		a[f-1][0]+=x;
		a[f-1][1]+=1;
	}
	for (int i=0; i<2; i++){
		if (a[i][0]<a[i][1]*5){
			cout << "DEAD\n";
		}
		else{
			cout << "LIVE\n";
		}
	}
	return 0;
}