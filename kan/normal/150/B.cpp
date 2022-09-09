#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const ll mod=1000000007;
const int maxn=2005;

int e[maxn][maxn];
int was[maxn];
ll n,m,k;

void go(int cur)
{
	if (was[cur]==1) return;
	was[cur]=1;
	for (int i=0;i<n;i++) if (e[cur][i]) go(i);
}

int main()
{
	memset(was,0,sizeof(was));
	memset(e,0,sizeof(e));
	cin >> n >> m >> k;
	for (int i=0;i<n-k+1;i++)
	{
		for (int j=0;j<k;j++)
		{
// 			cerr << "calc "<< i+j << ' ' << i+(k-j-1) << endl;
			e[j+i][i+(k-j-1)]=1;
			e[i+(k-j-1)][i+j]=1;
		}
	}
	int kv=0;
	for (int i=0;i<n;i++) if (was[i]==0)
	{
		kv++;
		go(i);
	}
	ll answer=1;
	for (int i=0;i<kv;i++) answer=(answer*m)%mod;
	cout << answer << endl;
	return 0;
}