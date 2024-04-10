#include<bits/stdc++.h>
using namespace std;

int pot[2];

int main(){
	int cnt = 0;
    string s;
    cin >> s;
    for(int i = 0 ; i < s.size() ; i++)
    	if(s[i] == 'Q'){
    		cnt += pot[1];
    		pot[0]++;
		}
		else
			if(s[i] == 'A')
				pot[1] += pot[0];
	cout << cnt;
	return 0;
}