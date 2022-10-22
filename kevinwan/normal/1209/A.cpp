#include<bits/stdc++.h>
#ifdef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;

const int mn=1e6+10;
bool a[mn];
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
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a[x]=1;
	}
	int ans=0;
	for(int i=1;i<mn;i++)if(a[i]){
		for(int j=i;j<mn;j+=i)a[j]=0;
		ans++;
	}
	printf("%d",ans);
}