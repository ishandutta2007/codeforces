#include<iostream>
#include <cstdio>
#include<algorithm>
#include<map>
#include<string>
              
#define inf (1<<30) 
#define s second
#define sz 100000
#define f first

using namespace std;

char a[123][123],b[123][123];
int n,m;

int main(){     
	cin>>n>>m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			if (((i+j)%2)==0) b[i][j]='B'; else b[i][j]='W';
			cin>>a[i][j];
			if (a[i][j]=='-') b[i][j]='-';
		}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) 
			cout<<b[i][j];
		cout<<endl;	
	}
		


	return 0;
}