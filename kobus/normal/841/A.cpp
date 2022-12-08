#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000007

int v[28];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,k;
	cin>>n>>k;

	for(int i=0;i<n;i++){
		char y;
		cin>>y;
		v[y-'a']++;
	}
	for(int i=0;i<28;i++){
		if(v[i]>k){
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";

	return 0;
}