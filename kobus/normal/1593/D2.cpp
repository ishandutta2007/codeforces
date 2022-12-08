#include<bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int> div(int x){
	vector<int> ans;
	int j=1;
	while(j*j<=x){
		if(x%j==0){
			ans.pb(j);
			ans.pb(x/j);
		}
		j++;
	}
	return ans;
}

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++)cin>>v[i];
		sort(v.begin(),v.end());
		int ans=1;
		for(int i=0;i<n;i++){
			//i eh o min
			int eq=0;
			for(int j=i;j<n;j++){
				if(v[i]==v[j])eq++;
			}
			if(eq>=n/2){
				ans=INT_MAX;
				break;
			}
			for(int j=i+eq;j<n;j++){
				for(int x:div(v[j]-v[i])){
					int eqq=0;
					for(int k=i+eq;k<n;k++){
						if((v[k]-v[i])%x==0)eqq++;
					}
					if(eq+eqq>=n/2){
						ans=max(ans,x);
					}
				}
			}
		}
		if(ans==INT_MAX)ans=-1;
		cout<<ans<<endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
	}
}