#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main(){
	int n;
	cin >> n;
	n *= 2;
	vector<int> a(n);
	for(int i =0; i< n; i++)
		cin >> a[i];
	int cnt =0;
	vector<bool> used(n + 1);
	int mx =0;
	for(int i =0; i< n; i++){
		if(!used[a[i]]){
			cnt++;
			mx =max(cnt, mx);
			used[a[i]] = 1;
		}
		else
			cnt--;
	}
	cout << mx;
	return 0;
}