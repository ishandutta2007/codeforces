#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)){
	    if(c == '-')
			f = 1;
        c = getchar();
    }
    while(isdigit(c)){
		a = (a << 3) + (a << 1) + (c ^ '0');
		c = getchar();
	}
	return f ? -a : a;
}

int main(){
	string s;
	cin >> s;
	int len = 0 , p = -1 , q = -1;
	bool f = 0;
	for(int i = 0 ; i < s.size() ; ++i)
		if(s[i] == '['){
			p = i;
			break;
		}
	for(int i = s.size() - 1 ; i >= 0 ; --i)
		if(s[i] == ']'){
			q = i;
			break;
		}
	if(p < q && p != -1 && q != -1){
		int r = -1 , m = -1;
		for(int i = p + 1 ; i < q ; ++i)
			if(s[i] == ':'){
				r = i;
				break;
			}
		for(int i = q - 1 ; i > p ; --i)
			if(s[i] == ':'){
				m = i;
				break;
			}
		if(r < m && r != -1 && m != -1){
			f = 1;
			len = 4;
			for(int j = r + 1 ; j < m ; ++j)
				if(s[j] == '|')
					++len;
		}
	}
	cout << (f ? len : -1);
	return 0;
}