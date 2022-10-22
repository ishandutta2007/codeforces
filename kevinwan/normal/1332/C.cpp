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
int num[26];
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
    	int n,k;
    	cin>>n>>k;
    	string s;
    	cin>>s;
    	int ans=0;
    	for(int i=0;i<(k+1)/2;i++){
    		memset(num,0,sizeof(num));
    		for(int j=0;j<n;j+=k){
    			num[s[i+j]-'a']++;
    			if(i*2+1!=k)num[s[k-i-1+j]-'a']++;
    		}
    		int mo=0;
    		for(int i=0;i<26;i++)mo=max(mo,num[i]),fprintf(stderr,"%d ",num[i]);
    		fprintf(stderr,"\n");
    		ans+=mo;
    	}
    	printf("%d\n",n-ans);
    	fprintf(stderr,"\n");
    }
}