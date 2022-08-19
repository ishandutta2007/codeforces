#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

int main(){
	int n, a = 0, b = 0;
	cin >> n;
	vector<int> w;
	while(n--){
		int k;
		scanf("%d",&k);
		for(int i=0; i<k; i++){
			int x;
			scanf("%d",&x);
			if(k%2 == 1 && k/2 == i){
				w.push_back(x);
			}
			else{
				if(i < k/2){
					a += x;
				}
				else b += x;
			}
		}
	}
	sort(w.begin(), w.end());
	reverse(w.begin(), w.end());
	for(int i=0; i<w.size(); i++){
		if(i%2 == 0) a += w[i];
		else b += w[i];
	}
	cout << a << " " << b;
}