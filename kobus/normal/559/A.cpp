#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second

typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567
#define INF INT_MAX/2
#define MOD 1000000007
#define int long long

int v[312345];

int fa(int l3){
	return (l3*l3);
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int c,ce,cd,be,bd,b;
	cin>>c>>cd>>bd>>b>>be>>ce;

	int l3=c+cd+bd;

	int atot=l3*l3;
	atot-=fa(be);
	atot-=fa(bd);
	atot-=fa(c);

	cout<<atot<<endl;


	return 0;
}