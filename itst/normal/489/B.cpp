#include<bits/stdc++.h>
using namespace std;
int Boy[101] , Girl[101];
int main()
{
	int i = 0 , j = 0 , cou = 0 , numB , numG;
	cin >> numB;
	for(int i = 0 ; i < numB ; i++)	cin >> Boy[i];
	cin >> numG;
	for(int i = 0 ; i < numG ; i++)	cin >> Girl[i];
	sort(Boy , Boy + numB);
	sort(Girl , Girl + numG);
	while(i < numB && j < numG)
	{
		while(i < numB && j < numG && Boy[i] - Girl[j] < -1)	i++;
		while(i < numB && j < numG && Boy[i] - Girl[j] > 1)	j++;
		if(i < numB && j < numG && abs(Boy[i] - Girl[j]) <= 1)
		{
			cou++;
			i++;
			j++;
		}
	}
	cout << cou;
	return 0;
}