#include <iostream>
#include <deque>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int p[301];
	int a[301][301]={};
	bool b[301]={};
	vector<int> ind;
	vector<int> val;
	char c;
	for(int i=0;i<n;i++){
		cin >> p[i];
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c = '\n';
			while(c=='\n') cin >> c;
			if(c=='1'){
				a[i][j]=1;
			}
		}
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i][k]==1 && a[k][j]==1){
					a[i][j]=1;
					a[j][i]=1;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(b[i])
			continue;
		val.clear();
		ind.clear();
		ind.push_back(i);
		b[i]=true;
		val.push_back(p[i]);
		for(int j=i+1;j<n;j++){
			if(a[i][j]){
				ind.push_back(j);
				b[j]=true;
				val.push_back(p[j]);
			}
		}
		sort(val.begin(),val.end());
		for(int j=0;j<ind.size();j++){
			p[ind[j]] = val[j];
		}
	}
	for(int i=0;i<n;i++){
		if(i!=0){
			cout <<" ";
		}
		cout << p[i];
	}
	return 0;
}