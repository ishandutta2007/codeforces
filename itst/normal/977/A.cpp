#include<bits/stdc++.h>
using namespace std;
int main(){
    int a , b;
    for(cin >> a >> b ; b ; b--)
    	if(a % 10)	a--;
    	else	a /= 10;
    cout << a;
    return 0;
}