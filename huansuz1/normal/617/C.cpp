#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#define ll long long
using namespace std;



int x[2345],y[2345],n;
ll ans=1000000000000000000ll,r,r1,r2,a,b,c,d;
int main(){
	cin>>n>>a>>b>>c>>d;
	for (int i=0; i<n; i++)
		cin>>x[i]>>y[i];
	
	for (int i=0; i<n; i++){
		r=((a-x[i])*(a-x[i])+(b-y[i])*(b-y[i]));			
	    r1=0;
	    for (int j=0; j<n; j++)
	    	if (i!=j) {
	    		ll q=((a-x[j])*(a-x[j])+(b-y[j])*(b-y[j]));
	    		if (q>r) {
	    			r2=((c-x[j])*(c-x[j])+(d-y[j])*(d-y[j]));
	    			r1=max(r1,r2); 
	    		}
	    	}
	    ans=min(ans,r1+r);
	}
	swap(a,c);
	swap(b,d);
	for (int i=0; i<n; i++){
		r=((a-x[i])*(a-x[i])+(b-y[i])*(b-y[i]));			
	    r1=0;
	    for (int j=0; j<n; j++)
	    	if (i!=j) {
	    		ll q=((a-x[j])*(a-x[j])+(b-y[j])*(b-y[j]));
	    		if (q>r) {
	    			r2=((c-x[j])*(c-x[j])+(d-y[j])*(d-y[j]));
	    			r1=max(r1,r2); 
	    		}
	    	}
	    ans=min(ans,r1+r);
	}


	cout<<ans;


    return 0;             
}