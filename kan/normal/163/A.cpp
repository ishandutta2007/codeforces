#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
// 	#define LLD "%lld"
#endif

const int maxn=5005;
const ll mod=1000000007;

ll k[2][maxn][4];
string s,t;

int main()
{
	cin >> s;
	cin >> t;
	int n=s.length();
	int m=t.length();
	s=' '+s;
	t=' '+t;
	memset(k,0,sizeof(k));
	for (int i=1;i<=n;i++)
	{
// 		cout << i << endl;
		for (int j=1;j<=m;j++)
		{
// 			cout << "j: " << j << endl;
			k[1][j][1]=k[1][j-1][1];
// 			k[1][j][2]=k[0][j][2];
			k[1][j][0]=(k[1][j-1][1]+k[0][j][0])%mod;
// 			cout << k[1][j][0] << ' ' << k[0][j][2] << endl;
			if (s[i]==t[j])
			{
				k[1][j][1]+=1+k[0][j-1][1];
				k[1][j][1]%=mod;
// 				k[1][j][2]+=1+k[0][j-1][1];
// 				k[1][j][2]%=mod;
				k[1][j][0]+=1+k[0][j-1][1];
				k[1][j][0]%=mod;
			}
		}
		for (int j=1;j<=m;j++)
		{
// 			cout << i << ' ' << j << ' ' << k[1][j][0] << endl;
			k[0][j][0]=k[1][j][0];
			k[0][j][1]=k[1][j][1];
			k[0][j][2]=k[1][j][2];
		}
	}
	cout << k[1][m][0] << endl;
	return 0;
}