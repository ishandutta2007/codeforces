#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
 
const int mn = 2e5+10;
const ll mod = 1e9+7;

string s[mn];
int b[3],w[3];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	while(tc--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)cin>>s[i];
		int num=0;
		b[0]=b[1]=b[2]=w[0]=w[1]=w[2]=0;
		for(int i=0;i<n;i++)for(int j=0;j<n;j++){
			++num;
			if(s[i][j]=='X')++b[(i+j)%3];
			else if(s[i][j]=='O')++w[(i+j)%3];
			else --num;
		}
		int bn=-1,wn=-1;
		for(int i=0;i<3;i++)for(int j=0;j<3;j++)if(i!=j){
			if(b[i]+w[j]<=num/3)bn=i,wn=j;
		}
		assert(bn>=0);
		for(int i=0;i<n;i++)for(int j=0;j<n;j++){
			if((i+j)%3==bn&&s[i][j]!='.')s[i][j]='O';
			if((i+j)%3==wn&&s[i][j]!='.')s[i][j]='X';
		}
		for(int i=0;i<n;i++)printf("%s\n",s[i].c_str());
	}
}