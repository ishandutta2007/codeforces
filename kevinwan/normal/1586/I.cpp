#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
const double PI = acos(-1.L);
const int mn = 2e3+10;
const int SIZE = 600;
const int BLOCKS = mn/SIZE+10;
const ll mod = 1e9+7;
string g[mn];
int a[mn][mn],b[mn][mn];
int c[mn];
int main(){
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>g[i];
	if(n%2==1){
		printf("NONE\n");
		return 0;
	}
	for(int i=0;i<n;i++){
		if(i%2==0){
			for(int j=0;j<=i;j++){
				a[i-j][j]=i/2;
				b[i-j][j]=(j^(i/2))&1;
			}
		}
		else{
			for(int j=0;j<=i;j++){
				b[i-j][j]=(i%4==3);
				a[i-j][j]=max(i/2-j,j-i/2-1);
			}
		}
	}
	for(int i=0;i<n;i++)for(int j=n-i;j<n;j++){
		a[i][j]=a[n-1-i][n-1-j];
		b[i][j]=b[n-1-i][n-1-j];
	}
	memset(c,-1,sizeof(c));
	for(int i=0;i<n;i++)for(int j=0;j<n;j++){
		if(g[i][j]=='.')continue;
		int val = (g[i][j]=='S')^b[i][j];
		if(c[a[i][j]]!=-1&&c[a[i][j]]!=val){
			printf("NONE\n");
			return 0;
		}
		c[a[i][j]]=val;
	}
	for(int i=0;i<n/2;i++)if(c[i]==-1){
		printf("MULTIPLE\n");
		return 0;
	}
	printf("UNIQUE\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%c",(c[a[i][j]]^b[i][j])?'S':'G');
		}
		printf("\n");
	}
}