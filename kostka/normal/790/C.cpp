#include "bits/stdc++.h"

using namespace std;

long long dp[77][77][77][3];
const long long INF = 1LL<<60;

int code(char letter)
{
  if(letter == 'V')
	  return 1;
  if(letter == 'K')
	  return 2;
	return 0;
}

int n;
string x;

int cost(vector <int> ammount, int letter)
{
  int ile = 0;
	int dokad = ammount[0]+ammount[1]+ammount[2];
  for(int i=0; i<n; i++)
	{
    int w = code(x[i]);
		if(w == letter and ammount[w] == 0)
		  break;
		if(ammount[w] == 0)
		  ile++;
    else
		  ammount[w]--;
	}
	return ile;
}

int main()
{
	cin >> n >> x;
  vector <int> ile(3);
	for(auto lit : x)
	  ile[code(lit)]++;
  for(int i=0; i<=ile[0]; i++)
	  for(int j=0; j<=ile[1]; j++)
		  for(int k=0; k<=ile[2]; k++)
			  for(int l=0; l<3; l++)
				  dp[i][j][k][l] = INF;
	dp[0][0][0][0] = dp[0][0][0][1] = dp[0][0][0][2] = 0;
	//cerr << ile[0] << " " << ile[1] << " " << ile[2] << "\n";
  for(int i=0; i<=ile[0]; i++)
	  for(int j=0; j<=ile[1]; j++)
			for(int k=0; k<=ile[2]; k++)
			  for(int l=0; l<3; l++)
			  {
				  vector <int> ammount = {i,j,k};
					if(i+1 <= ile[0])
			      dp[i+1][j][k][0] = min(dp[i+1][j][k][0], dp[i][j][k][l] + cost(ammount,0));
				  if(j+1 <= ile[1])
					  dp[i][j+1][k][1] = min(dp[i][j+1][k][1], dp[i][j][k][l] + cost(ammount,1));
					if(k+1 <= ile[2] and l != 1)
					  dp[i][j][k+1][2] = min(dp[i][j][k+1][2], dp[i][j][k][l] + cost(ammount,2));
				}
  //for(int i=0; i<=ile[0]; i++)
	//  for(int j=0; j<=ile[1]; j++)
	//	  for(int k=0; k<=ile[2]; k++)
	//		  for(int l=0; l<3; l++) 
	//			  cerr << i << " " << j << " " << k << " " << l << ": " << dp[i][j][k][l] << "\n";
	long long res = INF;
	for(int l=0; l<3; l++)
	  res = min(res, dp[ile[0]][ile[1]][ile[2]][l]);
  cout << res << "\n";
	return 0;
}