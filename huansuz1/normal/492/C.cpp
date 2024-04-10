#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
using namespace std;
pair<long long , long long > a[123456];
long long n,x,y,k;
long long s,l;

int main() {
    cin>>n>>x>>y;
    for (int i=1; i<=n; i++) {
    	cin>>a[i].second>>a[i].first;     
    	s+=a[i].second;    	
    }
    sort(a+1,a+n+1);
    int i=1;

    while(s<(n*y)){
    	s+=x-a[i].second; 
    	l+=(x-a[i].second)*a[i].first; 
    	k=i;
    	i++;
    }

    l-=((s-(n*y))*a[k].first);
    cout<<l;

    return 0;
}