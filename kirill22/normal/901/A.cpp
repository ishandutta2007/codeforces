#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n,ans=0,co=0;
    bool flag=false;
    cin >> n;
    vector<int> a(n+1);
    for(int i=0;i<n+1;i++){
    	cin >> a[i];
    	if (a[i]!=1){
    		co++;
    	}
    	else{
    		co=0;
    	}
    	if (co>=2){
    		flag=true;
    		
    	}
    }
    if (!flag){
    	cout << "perfect";
    	return 0;
    }
    cout << "ambiguous" << endl;
    ll pr=1,h=1;
    for(int i=0;i<n+1;i++){
    	for(int u=0;u<a[i];u++){
    		cout << pr-1 << " ";
    		h++;
    	}
    	pr=h;
    }
    cout << endl;
    pr=1,h=1;
    
    for(int i=0;i<n+1;i++){
    	if (i>0 && a[i]!=1 && a[i-1]!=1 && flag==true){
    		flag=false;
    		for(int u=0;u<a[i];u++){
    			if (u==0){
    				cout << pr-2 << " ";
    				h++;
    				continue;
    			}
    		cout << pr-1 <<  " ";
    		h++;
    	}
    	pr=h;
    		
    	}
    	else{
    		for(int u=0;u<a[i];u++){
    		cout << pr-1 <<  " ";
    		h++;
    	}
    	pr=h;
    	}
    }
    
    
    
    
}