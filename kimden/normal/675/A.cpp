#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c;
	int i,j;
	cin >> a >> b >> c;
	if(c==0){
		if(a!=b){
			cout << "NO";
		}else{
			cout << "YES";
		}
		return 0;
	}
	i = (b<0 ? -b : b);
	j = (a<0 ? -a : a);
	int k = (c<0 ? -c : c);
	if((((long long)b)-(long long)a)%k!=0){
		cout << "NO";
		return 0;
	}
	if((b<a && c>0)||(b>a && c<0)){
		cout << "NO";
		return 0;
	}
	cout << "YES";
	return 0;
}