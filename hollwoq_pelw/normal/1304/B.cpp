#include <bits/stdc++.h>
using namespace std;

bool re(string i, string j){
    reverse(i.begin(), i.end()); 
    return i == j;
}
int main(){
	int n, m;
	cin >> n >> m;
	string a[n];
	string h = "", t = "", mid = "";
	for (int i = 0; i < n; i++) cin >> a[i];
	set <int> used;
	for (int i = 0; i < n-1; i++){
	    if (used.count(i)){
	        continue;
	    }
	    for (int j = i+1; j < n; j++){
	        if (used.count(j)){
	            continue;
	        }
	        else if (re(a[i],a[j])){
	            h = a[i] + h;
	            t = t + a[j];
	            used.insert(i);
	            used.insert(j);
	            break;
	        }
	    }
	}
	for (int i = 0; i < n; i++){
	    if (!used.count(i)){
	        if (re(a[i],a[i])){
	            mid = a[i];
	            break;
	        }
	    }
	}
	string res = h+mid+t;
	cout << res.length() << endl;
	cout << res;
}