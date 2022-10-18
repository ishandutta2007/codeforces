//Krzysztof Boryczka
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
//END OF TEMPLATE

int n, maks, odp, j;
int t[100010];
bool vis[100010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	maks=-inf;
	FOR(i, 1, n){
		cin>>t[i];
		maks=max(maks, t[i]);
	}
	t[n+1]=-inf;
	FOR(i, 1, n){
		if(t[i]==maks && !vis[i]){
			j=i;
			while(t[j]==maks){
				vis[j]=true;
				j++;
			}
			odp=max(odp, j-i);
		}
	}
	cout<<odp<<ent;
	return 0;
}