#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007



int main()
{
	int n;
	cin >> n;
	int a;
	int ans = 0;
	int last = 0;
	vector<int> v;
	for(int i=0;i<n;i++){
		cin >> a;
		switch(a){
		case 0:
			last = 0;
			ans++;
			break;
		case 1:
			if(last==1){
				ans++;
				last = 0;
			}else{
				last = 1;
			}
			break;
		case 2:
			if(last==2){
				ans++;
				last = 0;
			}else{
				last = 2;
			}
			break;
		case 3:
			switch(last){
			case 0:
				last = 0;
				break;
			case 1:
				last = 2;
				break;
			case 2:
				last = 1;
				break;
			}
			break;
		}
	}
	cout << ans;
}