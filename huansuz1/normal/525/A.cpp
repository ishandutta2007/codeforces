#include <iostream>
#include <string>


using namespace std;


int n,a[123],z=0;
char x,y;

int main() {
cin>>n;
for (int i=1; i<=n-1; i++) {
	cin>>x>>y;
	if (x-'a'!=y-'A') {
		if (a[y-'A']==0) z++; else a[y-'A']--;
		a[x-'a']++;
	} 
}
cout<<z;
	
}