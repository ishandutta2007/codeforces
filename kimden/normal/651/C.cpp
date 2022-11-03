#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool lessX(pair<int,int> &a,pair<int,int> &b){
	return (a.first < b.first) || (a.first==b.first && a.second<b.second);
}
bool lessY(pair<int,int> &a,pair<int,int> &b){
	return (a.second < b.second) || (a.second==b.second && a.first<b.first);
}

int main()
{
	int n,x,y,k,l;
	long long ans=0;
	cin >> n;
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++){
		cin >> x >> y;
		v.push_back(make_pair(x,y));
	}
	sort(v.begin(),v.end(),lessX);
	k=0;
	l=0;
	for(vector<pair<int,int>>::iterator it=v.begin();it!=v.end();it++){
		if(it==v.begin()){
			k++;
			l++;
		}else{
			if(it->first==(it-1)->first){
				k++;
				if(it->second==(it-1)->second){
					l++;
				}else{
					ans-=((long long)l*(long long)(l-1))/2;
					l=1;
				}
			}else{
				ans+=((long long)k*(long long)(k-1))/2;
				k=1;
				ans-=((long long)l*(long long)(l-1))/2;
				l=1;
			}
		}
	}
	ans+=((long long)k*(long long)(k-1))/2;
	k=1;
	ans-=((long long)l*(long long)(l-1))/2;
	l=1;
	sort(v.begin(),v.end(),lessY);
	k=0;
	for(vector<pair<int,int>>::iterator it=v.begin();it!=v.end();it++){
		if(it==v.begin()){
			k++;
		}else{
			if(it->second==(it-1)->second){
				k++;
			}else{
				ans+=((long long)k*(long long)(k-1))/2;
				k=1;
			}
		}
	}
	ans+=((long long)k*(long long)(k-1))/2;
	k=1;
	cout << ans;
	return 0;
}