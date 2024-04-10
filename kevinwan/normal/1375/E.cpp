#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e3+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=998244353;
#define mid ((l+r)>>1)
int a[mn];
vector<pii>ans;
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=n-1;i>=0;i--){
    	vector<int>v;
    	for(int j=0;j<i;j++)if(a[j]>a[i])v.push_back(j);
    	sort(v.begin(),v.end(),[](int i,int j){if(a[i]!=a[j])return a[i]<a[j];return i<j;});
    	for(int x:v)ans.push_back({x,i});
    }
	printf("%d\n",ans.size());
	for(pii p:ans)printf("%d %d\n",p.first+1,p.second+1);
}