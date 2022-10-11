#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	int x=n/3;
	int a,b,c;
	a=x;
	for (int i=0; i<n; i++){
		if (s[i]=='0'){
			a--;
		}
	}
	b=x;
	for (int i=0; i<n; i++){
		if (s[i]=='1'){
			b--;
		}
	}
	c=x;
	for (int i=0; i<n; i++){
		if (s[i]=='2'){
			c--;
		}
	}
	for (int i=0; i<n; i++){
		if (s[i]=='2' and c<0){
			if (a>0){
				s[i]='0';
				a--;
				c++;
			}
			else if (b>0){
				s[i]='1';
				b--;
				c++;
			}
		}
		else if (s[i]=='1' && b<0){
			if (a>0){
				s[i]='0';
				a--;
				b++;
			}
		}
	}
	for (int i=n-1; i>-1; i--){
		if (s[i]=='0' and a<0){
			if (c>0){
				s[i]='2';
				a++;
				c--;
			}
			else if (b>0){
				s[i]='1';
				b--;
				a++;
			}
		}
		else if (s[i]=='1' && b<0){
			if (c>0){
				s[i]='2';
				c--;
				b++;
			}
		}
	}
	cout << s;
	return 0;
}