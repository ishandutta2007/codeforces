#include<iostream>

using namespace std;

int n,x,y,z;
char a[1234];

int main(){
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a[i];
		if (a[i]=='x') x++; else y++;
	}
	if (x>y) {
		for (int i=0; i<n; i++)	{
			if (x==y) break;
			if (a[i]=='x') {a[i]='X'; x--; y++; z++;}
		}
	} else {
	     for (int i=0; i<n; i++)	{
			if (x==y) break;
			if (a[i]=='X') {a[i]='x'; x++; y--; z++;}
		}
	}
	cout<<z<<endl;
	for (int i=0; i<n; i++)
		cout<<a[i];


	return 0;
}