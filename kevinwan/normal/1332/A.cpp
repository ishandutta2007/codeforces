#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=5e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;

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
    	int a,b,c,d;
    	cin>>a>>b>>c>>d;
    	int x,y,x1,y1,x2,y2;
    	cin>>x>>y>>x1>>y1>>x2>>y2;
    	bool gud=1;
    	if(a==b)gud&=(x1!=x2||!a);
    	else gud&=(x1<=x-a+b)&&(x-a+b<=x2);
    	if(c==d)gud&=(y1!=y2||!c);
    	else gud&=(y1<=y-c+d)&&(y-c+d<=y2);
    	printf("%s\n",gud?"Yes":"No");
    }
}