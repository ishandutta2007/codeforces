#include	<bits/stdc++.h>

using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int,int>pii;

#define MAXN 1000000007
#define INF 1123456789

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin>>n;

	if(n==1){
		cout<<"YES\n";
		return 0;
	}

	int part=0;

	int anterior;
	cin>>anterior;

	for(int i=0;i<n-1;i++){
		int y;
		cin>>y;
		if(y>anterior){
			if(part==1 || part==2){
				cout<<"NO\n";
				return 0;
			}
		}
		else if(y==anterior){
			if(part==2){
				cout<<"NO\n";
				return 0;
			}
			if(part==0){
				part=1;
			}
		}
		else{
			if(part==1 || part==0){
				part=2;
			}
			if(part==0){
				cout<<"NO\n";
				return 0;
			}
		}
		anterior=y;
	}
	cout<<"YES\n";
	return 0;
}