#include<iostream>
#include<cstdio>
#include<cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool my_pred(pair<string,int>&x,pair<string,int>&y){
   return x.second>y.second;
}

int main(){
   int n,m,a,b,k;
   string s;
   cin >> n >> m;
   vector<pair<string,int>> *v = new vector<pair<string,int>>[m];
   for(int i=0;i<m;i++){
	   v[i].clear();
   }
   for(int i=0;i<n;i++){
      cin >> s >> a >> b;
      v[a-1].push_back(make_pair(s,b));
   }
   for(int i=0;i<m;i++){
      sort(v[i].begin(),v[i].end(),my_pred);
	  if(v[i].size()>2){
		  if(v[i][2].second==v[i][1].second){
			  cout << "?\n";
		  }else{
			  cout << v[i][0].first << " " << v[i][1].first << "\n";
		  }
	  }else{
		  cout << v[i][0].first << " " << v[i][1].first << "\n";
	  }
   }
   return 0;
}