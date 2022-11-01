#include<bits/stdc++.h>
using namespace std;
char m[550][550];
int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
int main(){
	int R , C;
	cin >> R >> C;
	for(int i = 1 ; i <= R ; i++)
		for(int j = 1 ; j <= C ; j++)
			cin >> m[i][j];
	for(int i = 1 ; i <= R ; i++)
		for(int j = 1 ; j <= C ; j++)
			if(m[i][j] == 'W')
				for(int k = 0 ; k < 4 ; k++)
					if(m[dir[k][0] + i][dir[k][1] + j] == 'S')
					{
						cout << "No";
						return 0;
					}
	cout << "Yes" << endl;
	for(int i = 1 ; i <= R ; i++)
	{
		for(int j = 1 ; j <= C ; j++)
			if(m[i][j] == '.')	cout << "D";
			else	cout << m[i][j];
		if(i - R)	cout << endl;
	}
	return 0;
}