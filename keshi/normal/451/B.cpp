#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,l=1,r=0,a[100010],b[2];
	cin >> n;
	cin >> a[0];
	for (int i=1; i<n; i++){
		cin >> a[i];
		if (l*a[i]<l*a[i-1]){
			l*=-1;
			b[r]=i-1;
			r++;
		}
	}
	if (r>2){
		cout << "no";
	}
	else{
		if (r==0){
			cout << "yes\n1 1";
		}
		else if(r==1){
			if (b[0]==0 || a[n-1]>=a[b[0]-1]){
				cout << "yes\n" << b[0]+1 << ' ' << n;
			}
			else{
				cout << "no";
			}
		}
		else{
			if ((b[1]+1==n || a[b[0]]<=a[b[1]+1]) && (b[0]==0 || a[b[1]]>=a[b[0]-1])){
				cout << "yes\n" << b[0]+1 << ' ' << b[1]+1;
			}
			else{
				cout << "no ";
			}
		}
	}
	return 0;
}