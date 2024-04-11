#include <bits/stdc++.h>
 
using namespace std;
 
int n,k,s,t;
 
int main(){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> n >> k;
	while(n--)
		fin >> t,s+=t-(min(3,t/k)*k);
	fout << s;		
}