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
#define MOD 1000000

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a;
	string b;
	cin>>a>>b;

	int i4=0,i7=0;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			if(a[i]=='4')i4++;
			else i7++;
		}
	}
	cout<<max(i4,i7)<<endl;

	
	return 0;
}