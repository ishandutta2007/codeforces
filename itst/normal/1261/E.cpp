#include<bits/stdc++.h>
using namespace std;

vector < string > ans;
int N , arr[1003];
void create(vector < int > pot){
	string str(N , '0'); for(int i = 0 ; i < pot.size() ; ++i) str[pot[i] - 1] = '1';
	ans.push_back(str); for(int i = 0 ; i < pot.size() ; ++i) --arr[pot[i]];
}

bool cmp(int a , int b){return arr[a] < arr[b];}

int main(){
	cin >> N; for(int i = 1 ; i <= N ; ++i) cin >> arr[i];
	while(1){
		vector < int > lft;
		for(int i = 1 ; i <= N ; ++i) if(arr[i]) lft.push_back(i);
		sort(lft.begin() , lft.end() , cmp);
		if(arr[lft.back()] == 1){create(lft); break;}
		
		if(lft.empty()) break;
		if(lft.size() == arr[lft[0]]){
			create(lft);
			if(lft.size() != 1)
				for(int i = 0 ; i < lft.size() ; ++i){
					int t = lft[i]; lft.erase(lft.begin() + i); create(lft);
					lft.insert(lft.begin() + i , t);
				}
			break;
		}
		
		if(arr[lft[0]] != 1){
			create(lft);
			for(int i = 1 ; arr[lft[0]] && i < lft.size() ; ++i)
				if(arr[lft[i]] != 1){
					int t = lft[i]; lft.erase(lft.begin() + i); create(lft);
					lft.insert(lft.begin() + i , t);
				}else{
					vector < int > tmp; tmp.push_back(lft[0]);
					for(int i = 1 ; i < lft.size() ; ++i) if(1 != arr[lft[i]]) tmp.push_back(lft[i]);
					create(tmp);
				}
		}else{
			vector < int > tmp; tmp.push_back(lft[0]);
			for(int i = 0 ; i < lft.size() ; ++i) if(1 != arr[lft[i]]) tmp.push_back(lft[i]);
			create(tmp);
		}
	}
	cout << ans.size() << '\n';
	for(int i = 0 ; i < ans.size() ; ++i) cout << ans[i] << '\n';
	return 0;
}