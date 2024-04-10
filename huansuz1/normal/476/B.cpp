#include <algorithm>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
string s,l;
int x,y,z;
double d[105][1005];
int main(){
	cin>>s;
	cin>>l;
	for (int i=0; i<s.length(); i++)
		if (s[i]=='+')x++; else x--;
	for (int i=0; i<l.length(); i++){
		if (l[i]=='+')y++; else 
			if (l[i]=='-') y--; else z++;
	}
	int k = abs(x-y);
	d[0][100+k]=1;
	for (int i=1; i<=z; i++)
		for (int j=-40; j<=40; j++) {
			d[i][j+100]=(d[i-1][j-1+100]+d[i-1][j+1+100])*0.5;
		}
	printf("%.10lf", d[z][100]);
}