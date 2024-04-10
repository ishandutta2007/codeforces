#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
#define M 1000000007

int i,j,k,n,t,m,a[666],l,r,sb,res;
int main(){
	cin>>t;
	while(t--){
		res=0;
		cin>>n>>l>>r>>sb;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++){
			if(a[i]>=l&&a[i]<=r&&a[i]<=sb){
				sb-=a[i];res++;
			}
		}
		cout<<res<<'\n';
	}
}