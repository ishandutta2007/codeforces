#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin,s);
	const char *str;
	str = s.c_str();
	vector<char> symbols;
	vector<int> val;
	char c;
	int n;
	int plus,minus=0;
	int q=0;
	symbols.push_back('+');
	plus=1;
	do{
		sscanf(str+q,"%c",&c);
		q++;
		if(c=='=')  break;
		if(c!=' ' && c!='?'){
			symbols.push_back(c);
			plus += (c=='+' ? 1 : 0);
		}
	}while(1);
	minus = symbols.size()-plus;
	sscanf(str+q,"%c",&c);
	q++;
	sscanf(str+q,"%d",&n);
	int sum;
	sum = n*plus-minus;
	if((plus - n*minus > n) || (sum < n)){
		cout << "Impossible";
		return 0;
	}
	for(auto sign: symbols){
		if(sign=='-'){
			val.push_back(1);
		}else{
			val.push_back(n);
		}
	}
	int delta;
	for(int i=0;i<val.size();i++){
		delta = (sum - n >n-1 ? n-1 : sum - n);
		if(delta==0){
			break;
		}
		if(symbols[i]=='-'){
			val[i]+=delta;
		}else{
			val[i]-=delta;
		}
		sum -= delta;
	}
	cout << "Possible\n";
	cout << val[0] << " ";
	for(int i=1;i<val.size();i++){
		cout << symbols[i] << " " << val[i] << " ";
	}
	cout << "= " << n;
	return 0;
}