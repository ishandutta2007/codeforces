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

int ask(const vi &v){
	cout<<"?";
	for(int x:v)cout<<" "<<x;
	cout<<endl;
	int ind;
	cin>>ind;
	return ind-1;
}
int ans[mn];
int main()
{
    //cin.tie(0);
    //cin.sync_with_stdio(0);
	int n;
	cin>>n;
	vi v(n);
	fill(v.begin(),v.end(),n);
	for(int i=1;i<n;i++){
		int val=i-n;
		v[n-1]=i;
		int ind=ask(v);
		if(ind>=0)ans[ind]=val;
	}
	fill(v.begin(),v.end(),1);
	for(int i=2;i<=n;i++){
		int val=i-1;
		v[n-1]=i;
		int ind=ask(v);
		if(ind>=0)ans[ind]=val;
	}
	int mi=INT_MAX;
	for(int i=0;i<n;i++)mi=min(mi,ans[i]);
	for(int i=0;i<n;i++)ans[i]=ans[i]+1-mi;
	cout<<"!";
	for(int i=0;i<n;i++)cout<<" "<<ans[i];
	cout<<endl;
}