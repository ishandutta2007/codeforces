#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll mod=(1LL<<61)-1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const lll mul=57497633;
const int mn=8e3+10;
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
    	string s;
    	cin>>n>>s;
    	if(n>=3||s[1]>s[0])printf("YES\n2\n%c %s\n",s[0],s.c_str()+1);
    	else printf("NO\n");
    }
}