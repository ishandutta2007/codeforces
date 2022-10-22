#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n;
    cin >> n;
    vector<bool> ans(n,true);
    for(int i=0;i<n;i++){
    	int x,y;
    	
    	cin >> x >> y;
    	
    	if (y==0 && x!=-1){
    		ans[i]=false;
    		ans[x-1]=false;
    	}
    	if (x==-1){
    		ans[i]=false;
    	}
    }
    bool f=false;
    for(int i=0;i<n;i++){
    	if (ans[i]==true){
    		f=true;
    		break;
    	}
    }
    if(!f){
    	cout << -1;
    	return 0;
    }
    for(int i=0;i<n;i++){
    	if (ans[i]==true){
    		cout << i+1 <<" ";
    	}
    }
    
    

    return 0;

}