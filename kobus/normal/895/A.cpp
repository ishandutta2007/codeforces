#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF INT_MAX/2
#define MOD 1000000

int v[112345];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int p1=0;
	int p2=0;

	int n;
	cin>>n;

	int resp=360;

	for(int i=0;i<n;i++)cin>>v[i];

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			p1=0;
			p2=0;
			for(int k=0;k<n;k++){
				if(k<=i|| k>j)p1+=v[k];
				else p2+=v[k];
			}
			resp=min(resp,abs(p2-p1));
		}
	}

	cout<<resp<<endl;
	return 0;
}