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
#define INF INT_MAX;
#define MOD 1000000007

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,s=0,q=0;
	cin>>n;
	
	while(n>0){
		if(n%7!=0){
			n-=4;
			q++;
		}
		else{
			n-=7;
			s++;
		}
	}
	if(n!=0){
		cout<<-1<<endl;
	}
	else{
		for(int i=0;i<q;i++)cout<<4;
		for(int i=0;i<s;i++)cout<<7;
		cout<<endl;
	}

	return 0;
}