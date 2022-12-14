#include<iostream>
#include<cstdio>
#include<ctime>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<sstream>
//STL
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
//C++11 needed
#include<unordered_map>
#include<unordered_set>
#include<random>
using namespace std;

int arr[1003] , N , pos[1003];

int main(){
	cin >> N; vector < pair < int , int > > val;
	for(int i = 1 ; i <= N ; ++i){cin >> arr[i]; val.push_back(make_pair(arr[i] , i));}
	sort(val.begin() , val.end()); for(int i = 1 ; i <= N ; ++i) pos[i] = val[i - 1].second;
	vector < pair < int , int > > seq;
	for(int i = N - 1 ; i ; --i)
		for(int j = i ; j < N ; ++j)
			if(pos[j] > pos[j + 1]){
				seq.push_back(make_pair(pos[j + 1] , pos[j]));
				swap(pos[j] , pos[j + 1]);
			}else break;
	cout << seq.size() << endl;
	for(int i = 0 ; i < seq.size() ; ++i) cout << seq[i].first << ' ' << seq[i].second << endl;
	return 0;
}