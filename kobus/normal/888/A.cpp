#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 512345
#define INF INT_MAX/2
#define MOD 1000000007

int v[1123];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>v[i];

	int num=0;
	for(int i=1;i<n-1;i++){
		if(v[i]>v[i-1] && v[i]>v[i+1])num++;
		if(v[i]<v[i-1] && v[i]<v[i+1])num++;
	}

	cout<<num<<endl;

	return 0;
}