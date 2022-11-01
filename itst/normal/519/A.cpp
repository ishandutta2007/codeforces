#include<bits/stdc++.h>
using namespace std;
int vis[2];
int main(){
	char m;
	int dir;
	for(int i = 0 ; i < 64 ; i++)
	{
		dir = 0;
		cin >> m;
		if(m >= 'a' && m <= 'z')
		{
			dir++;
			m -= 32;
		}
		switch(m)
		{
			case 'Q':
				vis[dir] += 9;
				break;
			case 'R':
				vis[dir] += 5;
				break;
			case 'B':
			case 'N':
				vis[dir] += 3;
				break;
			case 'P':
				vis[dir]++;
				break;
		}
	}
	if(vis[0] > vis[1])
		cout << "White";
	else
		if(vis[0] < vis[1])
			cout << "Black";
		else
			cout << "Draw";
	return 0;
}