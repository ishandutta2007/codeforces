#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	int n,a;
	int arr[26];
	int beg=-1;
	int bg[26]={};
	for(int i=0;i<26;i++){
		arr[i]=-1;
	}
	cin >> n;
	getline(cin,s);
	for(int i=0;i<n;i++){
		getline(cin,s);
		if(bg[(int)s[0]-97]==0){
			bg[(int)s[0]-97]=1;
		}
		for(int j=0;j<s.length()-1;j++){
			arr[(int)(s[j])-97] = (int)s[j+1]-97;
			bg[(int)s[j+1]-97]=-1;
		}
	}
	for(int i=0;i<26;i++){
		if(bg[i]==1){
			a = i;
			while(a!=-1){
				cout << (char)(a+97);
				a = arr[a];
			}
		}
	}	
	return 0;
}