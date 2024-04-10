		#include<iostream>
		#include<algorithm>
		#include<cstdio>
		#include<string>

		using namespace std;

		int k,a[123],n,m,d,s,z;

		int main(){
			cin>>n>>d;
			for (int i=0; i<n; i++)
				cin>>a[i];
			cin>>m;	
			sort(a,a+n);
			for (int i=0; i<n; i++){
				z++;
				s+=a[i];
				if (z==m) break;
			}
			if (z<m) k=((m-z)*d);
			cout<<s-k;
			return 0;
		}