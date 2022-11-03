#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n,i,j,k,ans=13;
	vector<string> v;
	string a;
	v.clear();
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a;
		v.push_back(a);
	}
	for(vector<string>::iterator it = v.begin();it!=v.end();it++){
		for(vector<string>::iterator it2 = it+1; it2!=v.end();it2++){
			k=6;
			for(j=0;j<6;j++){
				if((*it)[j]==(*it2)[j])
					k--;
			}
			if(ans>k)
				ans = k;
		}
		if(ans<=2)
			break;
	}
	ans = (ans-1)/2;
	cout << ans;
	return 0;
}