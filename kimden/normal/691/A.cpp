#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	int c=0,a;
	for(int i=0;i<n;i++){
		cin >> a;
		if(a==0){
			c++;
		}
	}
	if((c==1 && n>1)||(n==1 && c==0)){
		cout << "YES";
	}else{
		cout << "NO";
	}
}