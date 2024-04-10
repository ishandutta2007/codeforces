#include<bits/stdc++.h>
using namespace std;
char m[51][51];
int main(){
	int R , C , maxR = 0 , minL = 2147483647 , maxD = 0 , minU = 2147483647;
	cin >> R >> C;
	for(int i = 0 ; i < R ; i++)
	{
		char c;
		scanf("%c" , &c);
		for(int j = 0 ; j < C ; j++)
		{
			scanf("%c" , &m[i][j]);
			if(m[i][j] == '*')
			{
				maxR = max(maxR , j);
				minL = min(minL , j);
				maxD = max(maxD , i);
				minU = min(minU , i);
			}
		}
	}
	for(; minU <= maxD ; minU++)
	{
		for(int i = minL ; i <= maxR ; i++)
			cout << m[minU][i];
		if(minU - maxD)
			cout << endl;
	}
	return 0;
}