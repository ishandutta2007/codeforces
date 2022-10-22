#include <bits/stdc++.h> 
using namespace std; 
 
signed long long splitlol(string str, set<char> dl) 
{ 
	signed long long w = 0; 
	str = str + '!'; 
	int l = str.size(); 
	signed long long res = 0; 
	for (int i = 0; i < l; i++) { 
 
		if (dl.count(str[i])) 
			w ++; 
		else { 
          	res += w*(w+1)/2;
			w = 0; 
		} 
	} 
 
	return res; 
} 
 
int main() 
{ 
	int n,k;
	string s;
	set<char> dl;
	char a;
	cin >> n >> k >> s;
	while(k){
	    k--;
	    cin >> a;
	    dl.insert(a);
	}
    cout << splitlol(s, dl);
	return 0; 
}