#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int N;
	for(cin >> N ; N ; N--){
		string s;
		cin >> s;
		int a = s.find('R') , b = s.find('C');
		bool f = 1;
		while(a != -1 && b != -1 && f && ++a < b)
			if(isdigit(s[a]))	f = 0;
		if(f == 1){
			int dirN = 0 , sum = 0;
			while(!isdigit(s[++dirN]));
			string s1 = string(s , 0 , dirN) , s2 = string(s , dirN , s.size() - dirN);
			cout << 'R' << s2 << 'C';
			for(int i = 0 ; i ^ dirN ; i++)
				sum = sum * 26 + s1[i] - 'A' + 1;
			cout << sum << endl;
		}
		else{
			string s1 = string(s , 1 , b - 1) , s2 = string(s , b + 1 , s.size() - b - 1) , s3;
			int a = atoi(s2.c_str());
			while(a)
			{
				if(a % 26 == 0){
					s3 = 'Z' + s3;
					a -= 26;
				}
				else	s3 = (char)(a % 26 + 'A' - 1) + s3;
				a /= 26;
			}
			cout << s3 << s1 << endl;
		}
	}
    return 0;
}