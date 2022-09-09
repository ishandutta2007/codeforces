#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;

const int maxn=50005;
const int maxk=505;

ll kv[maxn][maxk];
vector <int> gr[maxn];
int n,k;
ll ans;

void go(int cur,int pr)
{
// 	cout << "go " << cur << ' ' << pr << endl;
	for (int i=0;i<=k;i++) kv[cur][i]=0;
	kv[cur][0]=1;
	for (int i=0;i<gr[cur].size();i++) if (gr[cur][i]!=pr) go(gr[cur][i],cur);
// 	ans+=kv[cur][k];
	for (int i=0;i<k;i++)
	{
		ans+=kv[pr][k-(i+1)]*kv[cur][i];
	}
	for (int i=0;i<k;i++) kv[pr][i+1]+=kv[cur][i];
}

int main()
{
	ans=0;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) gr[i].resize(0);
	for (int i=0;i<n-1;i++)
	{
		int A,B;
		scanf("%d%d",&A,&B);
		A--;
		B--;
		gr[A].push_back(B);
		gr[B].push_back(A);
	}
	for (int i=0;i<=k;i++) kv[n][i]=0;
	go(0,n);
	cout << ans << endl;
	return 0;
}