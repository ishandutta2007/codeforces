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
int pwn[mn];
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
    	int n;
    	cin>>n;
    	for(int i=0;i<n;i++){
    		int x;
    		cin>>x;
    		for(int j=2;j*j<=x;j++){
    			if(x%j==0){
    				pwn[i]=j;
    				break;
    			}
    		}
    	}
    	map<int,int>m;
    	int c=0;
    	for(int i=0;i<n;i++){
    		if(!m.count(pwn[i]))m[pwn[i]]=++c;
    	}
    	printf("%d\n",c);
    	for(int i=0;i<n;i++)printf("%d ",m[pwn[i]]);
    		printf("\n");
    }
}