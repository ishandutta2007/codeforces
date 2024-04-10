#include<bits/stdc++.h>
using namespace std;
char m[3][3];
int main(){
	for(int i = 0 ; i < 9 ; i++)
	{
		scanf("%c" , &m[i / 3][i % 3]);
		if(i > 4)
			if(m[i / 3][i % 3] != m[2 - i / 3][2 - i % 3])
			{
				cout << "NO";
				return 0;
			}
		if(i % 3 == 2)	scanf("%c" , &m[1][1]);
	}
	cout << "YES";
	return 0;
}