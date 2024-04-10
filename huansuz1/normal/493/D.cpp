#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

#define pb push_back
#define mk make_pair
#define f first
#define s second
#define NN int(3e5)
const int Ma = 10000;

int n;

int main(){
//	freopen("in", "r", stdin);
    cin>> n;
    if (n == 2) {
     	cout << "white\n" << 1 << " " << 2;
     	return 0;
    }
    if (n == 3) {
     	cout << "black";
     	return 0;
    }            

    if (n % 2 == 0) {
     	cout << "white\n" << 1 << " " <<2;
     	return 0;
    }
    cout << "black\n";                    
	return 0;      
}