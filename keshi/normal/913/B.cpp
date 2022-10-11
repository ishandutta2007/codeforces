#include <bits/stdc++.h>
using namespace std;
map <int,bool> m;
int main(){
	int n,a[1010]={0},b,s[1010];
	cin >> n;
	for (int i=1; i<n; i++){
		cin >> s[i];
		m[s[i]-1]=1;
	}
	for (int i=0; i<n; i++){
		if (!(m[i])){
			a[s[i]-1]++;
		}
	}
	bool f=1;
	for (int i=0; i<n; i++){
		if (m[i] && a[i]<3){
			f=0;
			break;
		}
	}
	if (f){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	return 0;
}