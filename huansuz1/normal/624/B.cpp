#include <algorithm>
#include <iostream>
#include <cstring>                                               
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
int n,m;
long long ans;
map<int, int > mp;

int main(){
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>m;
		if (mp[m]==0) {mp[m]=1; ans+=m;} else {
			for (int j=m-1; j>=0; j--)
				if (mp[j]==0) {mp[j]=1; ans+=j; break;}
		}              
			
		
	}
cout<<ans;
    return 0;             
}