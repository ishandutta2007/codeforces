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

int n[4];

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int num;
	cin>>num;
	string s;
	cin>>s;


	for(int i=0;i<s.size();i++){
		if(s[i]=='L')n[0]++;
		if(s[i]=='R')n[1]++;
		if(s[i]=='U')n[2]++;
		if(s[i]=='D')n[3]++;
	}

	int tot=n[0]+n[1]+n[2]+n[3];

	int h=min(n[0],n[1]);
	n[0]-=h;
	n[1]-=h;

	int v=min(n[2],n[3]);
	n[2]-=v;
	n[3]-=v;

	cout<<tot-(n[0]+n[1]+n[2]+n[3])<<endl;

	return 0;
}