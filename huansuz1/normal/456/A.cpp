#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <cmath>      
#include <string>

#define f first
#define s second
#define sz 1000*1000

using namespace std;

int n;
pair<int, int> a[sz];

int main(){
	cin>>n;
	for (int i = 0; i < n; i++ ) 
		cin>>a[i].f>>a[i].s;
	sort(a, a+n);
	for (int i=0; i<n-1; i++)
		if (a[i].f < a[i+1].f && a[i].s > a[i+1].s) {
			cout<<"Happy Alex";
			return 0;
		}
	cout<<"Poor Alex"; 
	return 0;
}