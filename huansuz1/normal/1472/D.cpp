#include <bits/stdc++.h>
using namespace std;


int main() {
	int t, n, n1, n2;
	cin>>t;
	
	for(int i = 0; i < t; i++){
		cin>>n;
		int a1[n+9], a2[n+9], m;
		n1 = 1; n2 = 1;
		long long s1=0,s2=0;
		a1[0] = 0; a2[0] = 0;
		for(int j = 0; j < n; j++){
			cin>>m;
			if (m % 2 == 0) a2[n2++] = m; else a1[n1++] = m;
		}
		sort(a1,a1+n1);
		sort(a2,a2+n2);
		while(n >= 0){
		    n --;
		    if (n1 == 1 || (n2 > 1 && a1[n1-1] < a2[n2-1])) {n2--; s2 += a2[n2];} else n1--; 
		    n--;
		    if (n2 == 1 || (n1 > 1 && a2[n2-1] < a1[n1-1])) {n1--; s1 += a1[n1];} else n2--; 
		  
		}
		//cout<<s1<<" "<<s2<<endl;
		if (s2 > s1) cout<<"Alice"<<endl; else
		if (s2 < s1) cout<<"Bob"<<endl; else cout<<"Tie"<<endl;

	}

	return 0;
}