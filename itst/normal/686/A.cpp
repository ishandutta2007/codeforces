#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long sum;
    int N , cou = 0;
    for(cin >> N >> sum ; N ; N--){
    	char c;
    	int a;
    	cin >> c >> a;
    	if(c == '+')	sum += a;
    	else{
    		if(sum >= a)	sum -= a;
    		else	cou++;
		}
	}
	cout << sum << " " << cou;
    return 0;
}