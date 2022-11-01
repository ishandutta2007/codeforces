#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    for(int i = 1 ; i <= 100 ; i++)
    	if(i * (i + 1) / 2 == N){
    		cout << "YES";
    		return 0;
		}
	cout << "NO";
	return 0;
}