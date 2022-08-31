#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define si set<int>
#define sll set<ll>
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define mii map<int,int>
#define mll map<ll,ll>
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC


void gett()
{
	cerr<< (clock())/(double)cps<<endl;
}

const int maxn = 5e3+10;
const ll mod = 1e9+7;

pii row[maxn],col[maxn];
int main(){
	memset(row,0,sizeof row);
	memset(col,0,sizeof col);
	int n,m,k,r,a,c;
	cin>>n>>m>>k;
	for(int i = 1;i<=k;i++)
	{
		scanf("%d%d%d",&c,&r,&a);
		if(c == 1)
		{
			row[r] = mp(i,a);
		}
		else
		{
			col[r] = mp(i,a);
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++)
		{
			if(row[i].F > col[j].F)
				cout<<row[i].S<<" ";
			else
				cout<<col[j].S<<" ";
		}
		cout<<endl;
	}
}