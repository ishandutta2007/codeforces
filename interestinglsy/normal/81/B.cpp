#include <algorithm>
#include <iostream>
#include <string.h>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define F first
#define S second
#define INF 999999
#define ll long long
#define pb push_back
#define mp make_pair
#define LINF 999999999
#define sint short int
#define pii pair<int,int>
#define uint unsigned int
#define usint unsigned sint
#define LSY "A handsome man\n"
#define ull unsigned long long
#define ms(sss) memset(sss,0,sizeof(sss))
#define fms(cc,dd) memset(cc,dd,sizeof(cc))
#define DEBUG 0
#define debug if(DEBUG)
using namespace std;

#define DOU 9999
#define XXX 99999
#define SP 999999

char data[259];
uint pos = 0;
vector<char> ans;
vector<char>::iterator it;

int main(){
	ms(data);
	
	char c;
	while((c = cin.get())  !=  EOF){
		pos++;
		data[pos] = c;
	}
	pos--;
	for(uint k = 1;k <= pos;k++){
		if(data[k] == ',')
			if(k==pos){
					ans.pb(',');
				}else{
					ans.pb(',');ans.pb(' ');
				}
		else if(data[k] == '.')
			if(data[k-1]=='.'){
					ans.pb('.');
				}else{
					ans.pb(' ');ans.pb('.');
				}
		else //if(data[k] >= '0'  &&  data[k] <= '9')
			ans.pb(data[k]);
	}
	for(uint k = 1;k < ans.size();k++){
		if(ans[k] == ' '  &&  ans[k-1] == ' ') ans.erase(ans.begin()+(--k));
	}
	for(uint k = 1;k < ans.size();k++){
		if(ans[k] == ' '  &&  ans[k+1] != '.' && ans[k-1] != ',' && !(ans[k-1]>='0'&&ans[k-1]<='9'&&ans[k+1]>='0'&&ans[k+1]<='9')) ans.erase(ans.begin()+k);
	}
	debug
	for(uint k = 0;k < ans.size();k++)
		cout << ans[k];
	uint dot = 0;
	for(uint k = 0;k < ans.size();k++){
		if(ans[k] == '.') dot++; else dot = 0;
		if(dot >= 3){
			dot = 0;
			ans.insert(ans.begin() + k + 1,' ');
		}
	}
	for(uint k = 1;k < ans.size();k++){
		if(ans[k] == ' '  &&  ans[k+1] != '.' && ans[k-1] != ',' && !(ans[k-1]>='0'&&ans[k-1]<='9'&&ans[k+1]>='0'&&ans[k+1]<='9')) ans.erase(ans.begin()+k);
	}
	if(ans[0] == ' ') ans.erase(ans.begin());
	if(ans[ans.size()-1] == ' ') ans.erase(ans.begin()+ans.size()-1);
	for(uint k = 0;k < ans.size();k++)
		cout << ans[k];
	
    return 0;  
}