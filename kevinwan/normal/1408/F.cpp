#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e6+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
vector<pii>v;
void hail(int l,int r){
	if(l==r)return;
	hail(l,(l+r)/2);
	hail((l+r)/2+1,r);
	for(int i=l;i<=(l+r)/2;i++)v.push_back({i,i+(l+r)/2+1-l});
}
int main(){
	#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    int p=1<<31-__builtin_clz(n);
    hail(1,p);
    hail(n-p+1,n);
    printf("%d\n",v.size());
    for(pii p:v)printf("%d %d\n",p.first,p.second);
}