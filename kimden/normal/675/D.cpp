#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100056; // !
/*
struct num {
	int a;
	bool isLeft;
	bool isRight;
	num(int k=-1);
};

bool operator< (num&x,num&y){
	return x.a < y.a;
}
*/
int main()
{
	int n;
	cin >> n;
	int a[MAXN]={};
	int pred[MAXN]={};
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	map<int,int> mp;
	map<int,int>::iterator it,it2,it1;
	pair<map<int,int>::iterator,bool> pib;
	bool toLeft;
	mp[a[1]]=3;
	for(int i=2;i<=n;i++){
		pib = mp.insert(make_pair(a[i],3));
		it = pib.first;
		it2 = it;
		it1 = it;
		it2++;
		toLeft = false;
		if(it==mp.begin()){
			toLeft=false;
		}else{
			it1--;
			if(it2==mp.end()){
				toLeft = true;
			}else{
				if(it1->second%2==1){
					toLeft = true;
				}else{
					if(it2->second>=2){
						toLeft = false;
					}
				}
			}
		}
		if(toLeft){
			it1->second--;
			pred[i] = it1->first;
		}else{
			it2->second-=2;
			pred[i] = it2->first;
		}
	}
	for(int i=2;i<=n;i++){
		if(i>2){
			cout << " ";
		}
		cout << pred[i];
	}
	return 0;
}