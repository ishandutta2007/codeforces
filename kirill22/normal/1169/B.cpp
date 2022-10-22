#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> a(m);
    for(int i = 0;i < m;i++){
    	cin >> a[i].first >> a[i].second;
    }
    int x = a[0].first;
    int y = -1, y1 = -1;
    for(int i = 0;i < m;i++){
    	if(a[i].first != x && a[i].second != x){
    		y = a[i].first;
    		y1 = a[i].second;
    		break;
    	}
    }
    if(y == -1){
    	cout << "YES";
    	return 0;
    }
    bool f= true,fi = true;
    for(int i =0;i < m;i++){
    	if(a[i].first != x && a[i].second != x && a[i].first != y && a[i].second != y){
    		f = false;
    	}
    	if(a[i].first != x && a[i].second != x && a[i].first != y1 && a[i].second != y1){
    		fi = false;
    	}
    }
    if(fi || f){
    	cout << "YES";
    	return 0;
    }
    x = a[0].second;
    y = -1, y1 = -1;
    for(int i = 0;i < m;i++){
    	if(a[i].first != x && a[i].second != x){
    		y = a[i].first;
    		y1 = a[i].second;
    		break;
    	}
    }
    if(y == -1){
    	cout << "YES";
    	return 0;
    }
    f= true,fi = true;
    for(int i =0;i < m;i++){
    	if(a[i].first != x && a[i].second != x && a[i].first != y && a[i].second != y){
    		f = false;
    	}
    	if(a[i].first != x && a[i].second != x && a[i].first != y1 && a[i].second != y1){
    		fi = false;
    	}
    }
    if(fi || f){
    	cout << "YES";
    	return 0;
    }
    cout << "NO";
    
}