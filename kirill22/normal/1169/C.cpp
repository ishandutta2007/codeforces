#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, mod;
    cin >> n >> mod;
    vector<int> a(n);
    vector<int> b(n);
    for(int i = 0;i < n;i++){
    	cin >> a[i];
    	b[i] = a[i];
    }
    sort(b.begin(),b.end());
    if(a == b){
    	cout << 0;
    	return 0;
    }
    int l = 0, r = 300005;
    while(l + 1 < r){
    	int m = (l + r) / 2;
    	int tmp = 1e17;
    	bool f = true;
    	for(int i = n - 1;i > -1;i--){
    		if(i == n - 1){
    			if(a[i] + m >= mod){
    				tmp = mod - 1;
    			}
    			else{
    				tmp = a[i] + m;
    			}
    			continue;
    		}
    		if(a[i] + m < mod){
    			if(a[i] > tmp){
    				f = false;
    				break;
    			}
    			else{
    				tmp = min(tmp,a[i] + m);
    			}
    		}
    		else{
    			if(a[i] <= tmp){
    				tmp = tmp;
    			}
    			else{
    				int x = (a[i] + m) / mod;
    				if(x >= 2){
    					tmp = tmp;
    				}
    				else{
    					tmp = min(tmp,(a[i] + m) % mod);
    				}
    			}
    		}
    		
    		
    	}
    	
    	if(f){
    		r = m;
    	}
    	else{
    		l = m;
    	}
    }
    cout << r;
    
}