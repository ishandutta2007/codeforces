#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
void die(string S){puts(S.c_str());exit(0);}
int n;
string G[110];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>G[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(G[i][j]=='#')
			{
				if(!j||j==n-1||i>=n-2)
					die("NO");
				if(G[i+1][j-1]!='#'||G[i+1][j]!='#'||G[i+1][j+1]!='#'||G[i+2][j]!='#')
					die("NO");
				G[i][j]=G[i+1][j-1]=G[i+1][j]=G[i+1][j+1]=G[i+2][j]='.';
			}
	die("YES");
	return 0;
}