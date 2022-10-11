#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,c,p[1010],t[1010];
	cin >> n >> c;
	for (int i=0; i<n; i++){
		cin >> p[i];
	}
	for (int i=0; i<n; i++){
		cin >> t[i];
	}
	int a=0,b=0,m=0;
	for (int i=0; i<n; i++){
		m+=t[i];
		b+=max(0,p[i]-c*m);
	}
	m=0;
	for (int i=n-1; i>-1; i--){
		m+=t[i];
		a+=max(0,p[i]-c*m);
	}
	if (a>b){
		cout << "Radewoosh";
	}
	else if(a<b){
		cout << "Limak";
	}
	else{
		cout << "Tie";
	}
	return 0;
}