#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
    	cin >> a[i];
    	
    }
    int k;
    if (n>=16){
    	k=32;
    }
    else if(n>=8){
    	k=16;
    }
    else if(n>=4){
    	k=8;
    }
    else if(n>=2){
    	k=4;
    }
    else{
    	k=2;
    }
    while(k!=2){
    	k/=2;
    	for(int i=0;i<n;i+=k){
    		vector<int> b;
    		for(int u=i;u<i+k;u++){
    			b.push_back(a[u]);
    		}sort(b.begin(),b.end());
    		bool f=true;
    		for(int u=i;u<i+k;u++){
    			if(a[u]!=b[u-i]){
    				f=false;
    			}
    		}
    		if (f){
    			cout << k;
    			return 0;
    		}
    		
    	}
    }
    cout << 1;
    
    
    

    return 0;

}