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
#define INF LLONG_MAX;
#define MOD 1000000


int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,k;
	cin>>n>>k;
	k--;
	int mark=k-1;

	int menor=1;
	int maior=n;

	for(int i=0;i<k;i++){
		if(i%2==0){
			cout<<menor<<" ";
			menor++;
		}
		else{
			cout<<maior<<" ";
			maior--;
		}
	}
	if(k%2==0){
		for(int i=menor;i<=maior;i++)cout<<i<<" ";
	}	
	else for(int i=maior;i>=menor;i--)cout<<i<<" ";
	cout<<endl;
	
	return 0;
}