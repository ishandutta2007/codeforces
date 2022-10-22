#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=1e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;

int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int tc;
    cin>>tc;
    while(tc--){
    	int a,b,c;
    	cin>>a>>b>>c;
    	if(a<c)printf("1 ");
    	else printf("-1 ");
    	if(c<1LL*a*b)printf("%d\n",b);
    	else printf("-1\n");
    }
}