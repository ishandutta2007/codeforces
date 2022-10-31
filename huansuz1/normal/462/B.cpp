	#include<iostream>
	#include<algorithm>
	#include<cstdio>
	#include<string>

	using namespace std;

	char s;
	long long k,a[123],n,m,x,y;
	long long ss;

	int main(){
		cin>>n>>m;
		for (int i=0; i<n; i++){
			cin>>s;
			a[s-'A']++;
		}
			
		 sort(a,a+26);
		 for (int i=25; i>=0; i--) {
			x+=a[i];
			if (x<=m) {ss+=a[i]*a[i];} else {long long p=a[i]-(x-m); ss+=p*p; break;}
		}
		 cout<<ss;

	
		return 0;
	}