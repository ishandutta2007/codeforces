#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;
int n,x,y;
char a[1235][1234];
string s;
int main()
{
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			cin>>a[i][j];

	x=3;
	for (int i=0; i<3; i++){
		x--;
		y=3;
		for (int j=0; j<3; j++) {
		y--;
		if (a[i][j]=='X' && a[x][y]!='X') {cout<<"NO"; return 0;}
		}
	}	
	cout<<"YES";

	

	return 0;
}