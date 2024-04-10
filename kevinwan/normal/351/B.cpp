#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=4e3+10;
const ll inf=0x3f3f3f3f3f3f3f3f;

int a[mn];
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
    int num=0;
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
		if(a[i]>a[j])num++;
	}
	if(num&1)printf("%d",num/2*4+1);
	else printf("%d",num/2*4);
}