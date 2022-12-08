#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
//#define int long long
typedef long long ll;
typedef pair<int,int>pii;
#define MAXN 1123456
#define INF LLONG_MAX;
#define MOD 1000000

int men[1123];
int mai[1123];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m,s;
	cin>>m>>s;

	men[0]=1;
	mai[0]=1;

	if(s==0 || s>9*m){
		if(s==0 && m==1){
			cout<<"0 0\n";
			return 0;
		}
		cout<<"-1 -1\n";
		return 0;
	}
	s--;
	int sumax=s;
	for(int i=m-1;i>=0;i--){
		int num=min(sumax,9-mai[i]);
		mai[i]+=num;
		sumax-=num;
	}
	for(int i=0;i<m;i++)cout<<mai[i];
	cout<<" ";

	int sumin=s;
	for(int i=0;i<m;i++){
		int num=min(sumin,9-men[i]);
		cout<<men[i]+num;
		sumin-=num;
	}
	cout<<endl;
	

	return 0;
}