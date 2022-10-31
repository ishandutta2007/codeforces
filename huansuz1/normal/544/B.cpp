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
int n,m,k, b[123],z;
char a[1234][1234];
string s,l;


int main(){
cin>>n>>m;

    for (int i=1; i<=n; i++)
    	for (int j=1; j<=n; j++)
    		if (a[i-1][j]!='L' && a[i][j-1]!='L' && z<m) { z++; a[i][j]='L';} else a[i][j]='S';
	if (z<m) {cout<<"NO"; return 0;}
    cout<<"YES"<<endl;
    for (int i=1; i<=n; i++){
    	for (int j=1; j<=n; j++)
    		cout<<a[i][j];   
    	cout<<endl;		
    }

		    			
    	

}