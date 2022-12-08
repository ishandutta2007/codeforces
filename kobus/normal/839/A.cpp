#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
typedef long long ll;
typedef pair<int,int>pii;
 
#define MAXN 11234567890123
#define INF INT_MAX/2
#define MOD 1000000007

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,k;
	cin>>n>>k;

	int saved=0;
	int bran=0;
	int resp=1;
	for(int i=0;i<n;i++){
		int y;
		cin>>y;
		saved+=y;
		bran+=min(saved,8);
		saved-=min(saved,8);
		if(bran>=k){
			cout<<resp<<endl;
			return 0;
		}
		resp++;
	}
	cout<<-1<<endl;
	return 0;
}