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
    #define f first
    #define s second
    #define mp make_pair
    #define ll long long
     
    using namespace std;
    int n,h,m,c,h1,m1,c1,a,b,q;
	string t,s;
    int main(){
    cin>>n;
    cin>>s>>t;
    for (int i=0; i<n; i++){
    	a=s[i]-'0';
    	b=t[i]-'0';
    	if (a<b) swap(a,b);
    	q+=min(a-b,b+1+9-a); 
    }
    cout<<q;

	
	
	
	}