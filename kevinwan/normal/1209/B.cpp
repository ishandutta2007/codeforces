#include<bits/stdc++.h>
#ifdef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;

const int mn=120+10;
int a[mn],b[mn];
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
	string s;
	cin>>s;
	for(char&c:s)c-='0';
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	int ans=0;
	for(int i=0;i<mn;i++){
		for(int j=0;j<n;j++)if(i>=b[j]&&i%a[j]==b[j]%a[j])s[j]^=1;
		int cand=0;
		for(int j=0;j<n;j++)cand+=s[j];
		ans=max(ans,cand);
	}
	printf("%d",ans);
}