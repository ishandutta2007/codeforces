#include <bits/stdc++.h>
using namespace std;

struct pred{
	bool operator()(pair<int,int>&x, pair<int,int>&y){
		if(x.second != y.second){
			return x.second < y.second;
		}
		return x.first > y.first;
	}
};

int main()
{
	int t;
	int sum=0;
	vector<pair<int,int>> v(100);
	for(int i=0;i<100;i++){
		v[i].first = i+1;
	}
	for(int i=0;i<5;i++){
		cin >> t;
		sum+=t;
		v[t-1].second ++;
	}
	sort(v.begin(),v.end(),pred());
	int j=0;
	int k=0;
	while(j<100 && v[j].second<2){
		j++;
	}
	k=j;
	while(k<100 && v[k].second<3){
		k++;
	}
	if(j==100){
		cout << sum;
	}else{
		if(k==100){
			cout << sum - v[j].first*min(v[j].second,3);
		}else{
			cout << sum - max(v[j].first*min(v[j].second,3),v[k].first*min(v[k].second,3));
		}
	}
}