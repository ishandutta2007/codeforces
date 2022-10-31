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

map<int,int> st,ss;
map<int,int> :: iterator it;
pair<int,int> a[345678];
int n, x, m,b[345678];
char ch;

int main() {
    cin>>n;  
    for (int i = 1; i <= n; i++)
    {
     	cin>>x;
     	a[i].first=x; 
     	a[i].second=i;

    }
    sort(a+1,a+n+1);
    b[a[1].second]=a[1].first;
    for (int i=2; i<=n; i++)
    	if (a[i].first<=a[i-1].first) {a[i].first=a[i-1].first+1;b[a[i].second]=a[i].first; } else 
    		b[a[i].second]=a[i].first;

	for (int i=1; i<=n; i++)
		cout<<b[i]<<" ";
	return 0;
}