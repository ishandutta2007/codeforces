#include <bits/stdc++.h>
using namespace std;
long long solve(long long n){
	if(n<10) return max((long long)1,n);
	return max((n%10)*solve(n/10),9*solve(n/10-1));
}

int main(){
    long long n;
    cin >> n;
    cout << solve(n);
    return 0;
}