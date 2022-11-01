#include<bits/stdc++.h>
using namespace std;
char m[101][101];
int main(){
	int r , c;
	cin >> r >> c;
	for(int i = 0 ; i < c ; i++)
	{
		scanf("%c" , &m[100][100]);
		for(int j = 0 ; j < r ; j++)
			scanf("%c" , &m[i][j]);
	}
	for(int j = 0 ; j < r ; j++)
	{
		for(int i = 0 ; i < c ; i++)
			cout << m[i][j] << m[i][j];
		cout << endl;
		for(int i = 0 ; i < c ; i++)
			cout << m[i][j] << m[i][j];
		if(j + 1 - r)	cout << endl;
	}
	return 0;
}