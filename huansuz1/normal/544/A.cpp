#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define f first
#define s second
#define mp make_pair 
#define ll long long

using namespace std;


queue < pair < int , int > > q;
int n,m,k, a[1234],b[123],z;
string s,l;


int main(){
cin>>k>>s;
if (k==1){
	cout<<"YES"<<endl<<s;
	return 0;
}
for (int i=0; i<s.length(); i++) {
	if (a[s[i]]==0) { b[z]=i; z++; a[s[i]] =1;}  
	if (z==k) break;
		
}
	if (z<k) {cout<< "NO"; exit(0); }
	b[k]=s.length();

	cout<<"YES"<<endl;
	for (int i=0; i<z; i++){
			for (int j= b[i]; j<b[i+1]; j++)
				cout<<s[j]; 
				
			cout<<endl;			
	}


		    			
    	

}