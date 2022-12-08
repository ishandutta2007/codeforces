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
int num[112345];
int num2[112345];

map<int,int> m;

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,x,k;
	cin>>n>>x>>k;
	int resp=0;

	for(int i=0;i<n;i++)cin>>v[i];
	sort(v,v+n);

	for(int i=0;i<n;i++){
		int count=1;
		while(i+1<n && v[i+1]==v[i]){
			count++;
			i++;
		}
		num[i]=((v[i]-1)/x)+1;
		num2[i]=((v[i])/x)+1;
		m[num[i]]+=count;
		resp+=count*(m[num2[i]-k]);
	}
	cout<<resp<<endl;

	return 0;
}