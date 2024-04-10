#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int a,b,c,d,n;
string x,y,s[12];
int main(){
	cin >> x >> y;
	a=x[0]-'a'+1;
	b=x[1]-'0';
	c=y[0]-'a'+1;
	d=y[1]-'0';
	if (a<=c && b>=d && (a!=c || b!=d)) {
		while (a!=0) {
			if (a<c && b>d) {s[n++]="RD";a++;b--;} else
			if (a==c && b>d) {s[n++]='D';b--;} else
			if (a<c && b==d) {s[n++]='R';a++;}
			if (a==c && b==d) break;
		}	
	}
	if (a>=c && b<=d && (a!=c || b!=d)) {
		while (a!=0) {
			if (a>c && b<d) {s[n++]="LU";a--;b++;} else
			if (a==c && b<d) {s[n++]='U';b++;} else
			if (a>c && b==d) {s[n++]='L';a--;}
			if (a==c && b==d) break;
		}	
	}

	if (a>=c && b>=d && (a!=c || b!=d)) {
		while (a!=0) {
			if (a>c && b>d) {s[n++]="LD";a--;b--;} else
			if (a==c && b>d) {s[n++]='D';b--;} else
			if (a>c && b==d) {s[n++]='L';a--;}
			if (a==c && b==d) break;
		}	
	}

	if (a<=c && b<=d && (a!=c || b!=d)) {
		while (a!=0) {
			if (a<c && b<d) {s[n++]="RU";a++;b++;} else
			if (a==c && b<d) {s[n++]='U';b++;} else
			if (a<c && b==d) {s[n++]='R';a++;}
			if (a==c && b==d) break;
		}	
	}




	cout<<n<<endl; 
	for (int i=0; i<n; i++)
		cout<<s[i]<<endl;
	return 0;

}