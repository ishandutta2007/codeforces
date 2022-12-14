#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<cassert>
//This code is written by Itst
using namespace std;

int arr[100003];
string add(string a , string b){
	memset(arr , 0 , sizeof(arr));
	for(int i = 0 ; i < a.size() ; ++i)
		arr[a.size() - 1 - i] += a[i] - '0';
	for(int i = 0 ; i < b.size() ; ++i)
		arr[b.size() - 1 - i] += b[i] - '0';
	int t = max(a.size() , b.size());
	for(int i = 0 ; i < t ; ++i)
		if(arr[i] >= 10){
			arr[i] -= 10; arr[i + 1]++;
		}
	if(arr[t]) ++t;
	string X;
	for(int i = t - 1 ; i >= 0 ; --i)
		X = X + string(1 , arr[i] + '0');
	return X;
}

signed main(){
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
	#endif
	#define int long long
	int L; string N;
	cin >> L >> N;
	if(N.size() == 2){cout << (N[0] + N[1] - '0' - '0') << endl; return 0;}
	int p = (L / 2) , pos1 = p - 1 , pos2 = p;
	while(pos1 != -1 && N[pos1 + 1] == '0') --pos1;
	string num1 = N , num2 = N;
	if(pos1 != -1)
		num1 = add(string(N , 0 , pos1 + 1) , string(N , pos1 + 1 , (int)N.size() - pos1 - 1));
	while(pos2 + 1 < N.size() && N[pos2 + 1] == '0') ++pos2;
	if(pos2 + 1 != N.size())
		num2 = add(string(N , 0 , pos2 + 1) , string(N , pos2 + 1 , (int)N.size() - pos2 - 1));
	if(num1.size() > num2.size() || num1.size() == num2.size() && num1 > num2)
		num1 = num2;
	cout << num1;
	return 0;
}