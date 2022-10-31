#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
   
string s,t;
int ans;

int main() {
	cin>>s>>t;
	int n = s.size();
    	int m = t.size();
    	for (int i = 0; i < n; i++)
    		if (i+m-1 < n) {
    			bool ok = 0;
			for (int j = 0; j < m; j++)
				if (s[i+j]!=t[j]) {
					ok = 1;	
					break;
				}
			if (!ok) {
			 	s[i+m-1] = '#';
				ans++;
			}
    		}
	cout<<ans;
  
    return 0;
      
}