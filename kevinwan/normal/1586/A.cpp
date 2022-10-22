#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
const double PI = acos(-1.L);

const int mn = 1e6+10;
const ll mod = 1e9+7;

bool p[mn];

int a[mn];
void solve(){
	int n;
	cin>>n;
	int s=0;
	for(int i=0;i<n;i++)cin>>a[i],s+=a[i];
	if(!p[s]){
		printf("%d\n",n);
		for(int i=1;i<=n;i++){
			printf("%d ",i);
		}
		printf("\n");
		return;
	}
	for(int i=0;i<n;i++){
		if(!p[s-a[i]]){
			printf("%d\n",n-1);
			for(int j=0;j<n;j++)if(j!=i){
				printf("%d ",j+1);
			}
			printf("\n");
			return;
		}
	}
}

void init(){
	fill(p+2,p+mn,1);
	for(int i=2;i*i<mn;i++)if(p[i])for(int j=i*i;j<mn;j+=i)p[j]=0;
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
	init();
    int tc;
	cin>>tc;
	while(tc--){
		solve();
	}
}