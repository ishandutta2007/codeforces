#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int x,y,z,a,b,c;
    cin >> x >> y >> z >> a >> b >> c;
    if(a<x){
    	cout << "No";
    	return 0;
    }
    if (y>a-x+b){
    	cout << "No";
    	return 0;
    }
    if (z>a+b+c-x-y){
    	cout << "No";
    	return 0;
    }
    cout <<"Yes";


}