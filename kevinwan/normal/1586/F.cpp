#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
const double PI = acos(-1.L);

const int mn = 1e3+10;
const ll mod = 1e9+7;

int p[20];
int ans[mn][mn];
int m=0;
int n,k;
vi getmsk(int x){
	vi v(m);
	for(int i=0;i<m;i++,x/=k)v[i]=x%k;
	return v;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
	cin>>n>>k;
	p[0]=1;
	for(int i=1;p[i-1]<n;i++)p[i]=p[i-1]*k,m=i;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			vi a=getmsk(i), b=getmsk(j);
			int ind=0;
			while(a[ind]<=b[ind])ind++;
			ans[j][i]=ind;
		}
	}
	printf("%d\n",m);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			printf("%d ",ans[i][j]+1);
		}
	}
}