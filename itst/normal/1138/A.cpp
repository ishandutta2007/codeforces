#include<iostream>
//This code is written by Itst
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	//freopen("out","w",stdout);
#endif
	int N , pre = 0 , preCnt = 0 , cnt = 0 , Max = 0;
	cin >> N;
	for(int i = 1 ; i <= N ; ++i){
		int a;
		cin >> a;
		if(a == pre) ++cnt;
		else{
			Max = max(Max , min(preCnt , cnt) * 2);
			preCnt = cnt;
			cnt = 1;
			pre = a;
		}
	}
	cout << max(Max , min(preCnt , cnt) * 2);
	return 0;
}