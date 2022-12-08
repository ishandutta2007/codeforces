#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 212345
#define INF INT_MAX/2
#define MOD 1000000

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a,b,c;
	cin>>a>>b>>c;

	int count=0;
	while(count!=11234567){
		count++;
		a*=10;
		int num=a/b;
		a-=(num*b);
		if(num==c){
			cout<<count<<endl;
			return 0;
		}
	}

	cout<<-1<<endl;

	return 0;
}