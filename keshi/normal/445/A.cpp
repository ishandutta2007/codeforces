#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	string d,s="";
	for (int i=0; i<n; i++){
		cin >> d;
		for (int j=0; j<m; j++){
			if (d[j]!='-'){
				if ((i+j)%2==1){
					s+='W';
				}
				else{
					s+='B';
				}
			}
			else{
				s+='-';
			}
		}
		s+='\n';
	}
	cout << s;
	return 0;
}