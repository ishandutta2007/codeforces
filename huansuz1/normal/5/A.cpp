#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <math.h>
#include <set>
#include <queue>
#include <deque>
#include <map>
#include <ctime>
#include <cassert>
#include <cstring>
#include <string>

#define ll long long
#define f first
#define s second
#define mp make_pair

using namespace std;
queue < int > q;
string s[1235];
int a[1234];
int n,k,ans,z;


int main() {
	
	while(getline(cin,s[n])){
	n++;
	}	

	for (int j=0; j<n; j++)
	{
		string l=s[j];
		
		if (l[0]=='+') {z++;} else 
			if (l[0]=='-') z--; else {
				for (int i=0; i<l.length(); i++)
					if (l[i]==':') {k=l.length()-i-1; break;}
				ans+=(k*z);
			}
		

	}
	cout<<ans;




    return 0;
}