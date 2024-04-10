#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>

using namespace std;

char a[12][12];
int n,p;

int main(){
	for (int i=1; i<=4; i++)
		for (int j=1; j<=4; j++)
			cin>>a[i][j];
	for (int i=1; i<=3; i++)
		for (int j=1; j<=3; j++)
			if ((a[i][j]==a[i][j+1] && a[i][j]==a[i+1][j]) || (a[i][j]==a[i][j+1] && a[i][j]==a[i+1][j+1]) || (a[i][j]==a[i+1][j] && a[i][j]==a[i+1][j+1]) || (a[i+1][j]==a[i][j+1] && a[i][j+1]==a[i+1][j+1])) p=1;
	if (p==1) cout<<"YES"; else cout<<"NO";
	return 0;
}