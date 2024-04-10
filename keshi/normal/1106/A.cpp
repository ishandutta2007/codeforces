#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string a[510];
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	int s=0;
	for (int i=1; i<n-1; i++){
		for (int j=1; j<n-1; j++){
			if (a[i][j]=='X' && a[i][j]==a[i+1][j+1]){
				bool f=1;
				for (int n=-1; n<2; n++){
					for (int m=-1; m<2; m++){
						if (n!=0 && m!=0){
							if (a[i+n][j+m]!=a[i][j]){
								f=0;
							}
						}
					}
				}
				if (f){
					s+=1;
				}
				
			}
		}
	}
	cout << s;
	
	return 0;
}