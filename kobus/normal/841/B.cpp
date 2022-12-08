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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	bool odd=0;
	cin>>n;

	long long sum=0;

	for(int i=0;i<n;i++){
		int y;
		cin>>y;
		if(y%2==1){
			odd=1;
		}
		sum+=y;
	}
	if(sum%2==1){
		cout<<"First\n";
	}
	else if(odd==0){
		cout<<"Second\n";
	}
	else{
		cout<<"First\n";
	}

	return 0;
}