#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
const double PI = acos(-1.L);
const int mn = 1e5+10;
const ll mod = 998244353;

int t[3][3];
void mult(int c[3][3], int a[3][3], int b[3][3]){
	memset(t,0x3f,sizeof(t));
	for(int i=0;i<3;i++)for(int j=i;j<3;j++)for(int k=j;k<3;k++)
		t[i][k]=min(t[i][k],a[i][j]+b[j][k]);
	memcpy(c,t,sizeof(t));
}

int seg[mn*4][3][3];
void upd(int x,int l,int r,int a,int c){
	if(l==r){
		memset(seg[x],0,sizeof(seg[x]));
		seg[x][c-1][c-1]=1;
	}
	else{
		int mid=(l+r)/2;
		if(a<=mid)upd(x*2,l,mid,a,c);
		else upd(x*2+1,mid+1,r,a,c);
		mult(seg[x],seg[x*2],seg[x*2+1]);
		//cerr<<x<<" "<<seg[x][0][0]<<" "<<seg[x*2][0][0]<<" "<<seg[x*2+1][0][0]<<endl;
	}
}

void solve(){
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)upd(1,0,n-1,i,s[i]-'a'+1);
	while(q--){
		int ind;
		char c;
		cin>>ind>>c;
		--ind;
		upd(1,0,n-1,ind,c-'a'+1);
		printf("%d\n",seg[1][0][2]);
	}
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	

	int tc;
	tc=1;
	while(tc--)solve();
}