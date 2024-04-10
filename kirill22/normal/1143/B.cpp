#include<bits/stdc++.h>
using namespace std;
#define int long long

int f(int n1,int k){
	int ansi=1;
	for(int i=0;i<k;i++){
		ansi*=n1;
	}
	return ansi;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int k=n;
    int co=0;
    vector<int> z;
    while(k!=0){
    	co++;
    	z.push_back(k%10);
    	k/=10;
    }
    int ans = f(9,co-1);
    int a=z.size();
    int tmp=1;
    //cout << ans << endl;
    for(int i=a-1;i>-1;i--){
    	if (z[i]==0){
    		break;
    	}
    	ans=max(ans,tmp*(z[i]-1)*f(9,i));
    	
    	tmp*=z[i];
    	
    }
    ans=max(ans,tmp);
    cout << ans;
    
    

    return 0;

}