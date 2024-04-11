#include <bits/stdc++.h>

using namespace std;

long long t[100000];
long long r[100000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, wyn=-1;
	cin>>n>>m;
	for(int i=0; i<n; i++)
		cin>>t[i];
	for(int i=0; i<m; i++)
		cin>>r[i];
	long long l=0, p=0, nr1=0, nr2=0;
	while(nr1<n&&nr2<m){
		if(l==p){
			wyn++;
			l=0;
			p=0;
			l+=t[nr1];
			p+=r[nr2];
			nr1++;
			nr2++;
		}
		else if(l<p){
			l+=t[nr1];
			nr1++;
		}
		else if(l>p){
			p+=r[nr2];
			nr2++;
		}
	}
	if(nr1<n){
		while(l<p&&nr1<n){
			l+=t[nr1];
			nr1++;
		}
	}
	else if(nr2<m){
		while(p<l&&nr2<m){
			p+=r[nr2];
			nr2++;
		}
	}
	if(l==p&&l&&p){
		wyn++;
	}
	cout<<wyn<<'\n';
	return 0;
}