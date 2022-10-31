#include<iostream>
#include<algorithm>
#include<map>
#include<string>

using namespace std;

map <string, int> mp;
int n;
string s;
int main(){     
    cin>>n;
 	for (int i=0; i<n; i++){
 		cin>>s;
        mp[s]++;
        if (mp[s]==1) cout<<"OK"<<endl;
        	else
        		cout<<s<<mp[s]-1<<endl;	
 	}
 	
 	
 	
 	
 	
 	
 	return 0;          
}