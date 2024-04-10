#include<bits/stdc++.h>
using namespace std;
inline int abs(int a){
	return a > 0 ? a : -a;
}
int main(){
    int N;
    cin >> N;
    for(int i = 0 ; i <= (N << 1) ; i++)
    {
    	if(i)	cout << endl;
    	for(int j = 0 ; j < abs(N - i) ; j++)	cout << "  ";
    	for(int j = 0 ; j < N - abs(N - i) ; j++)	cout << j << ' ';
    	for(int j = N - abs(N - i) ; j ; j--)	cout << j << ' ';
    	cout << 0;
	}
    return 0;
}