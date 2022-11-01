#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<vector>
#include<cmath>
#include<random>
//This code is written by Itst
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c) && c != EOF){
        if(c == '-')
            f = 1;
        c = getchar();
    }
    if(c == EOF)
        exit(0);
    while(isdigit(c)){
	a = a * 10 + c - 48;
        c = getchar();
    }
    return f ? -a : a;
}

int main(){
    int T;
    for(cin >> T ; T ; --T){
	string s;
	int len;
	cin >> len >> s;
	if(s[0] == '<' && s[s.size() - 1] == '>'){
	    int cnt1 = 0 , cnt2 = 0;
	    for(int i = 0 ; i < s.size() && s[i] == '<' ; ++i)
		++cnt1;
	    for(int i = s.size() - 1 ; i >= 0 && s[i] == '>' ; --i)
		++cnt2;
	    cout << min(cnt1 , cnt2) << endl;
	}
	else cout << 0 << endl;
	
    }
    return 0;
}