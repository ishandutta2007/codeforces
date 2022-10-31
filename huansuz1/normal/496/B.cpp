#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>

using namespace std;

#define mod 1000000007
#define pii pair <int , int>
#define f first
#define s second
#define pb push_back
#define ll long long
    int n,m;
    	string s;
    	string l;
    int main(){
    	cin>>n;
    	cin>>s;
    	l=s;
    	for (int i=0; i<10; i++) {
    		for (int j=0; j<n; j++) {
    			s[j]+=1;	         
    			if (s[j]>'9') s[j]='0';
    			}
    		for (int j=0; j<n; j++) {
    			if (s<l) l=s;
    			char ss=s[n-1];
    			for (int o=n-1; o>=0; o--)	
    				s[o]=s[o-1];
    			s[0]=ss;
    			if (s<l) l=s;	
    		}                   
    	}
    	cout<<l;
    				




    return 0;
}