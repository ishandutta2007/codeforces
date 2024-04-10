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

#define int long long
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
#define PII pair < int , int >
#define st first
#define nd second

bool p(PII a , PII b){return a.st > b.st;}

signed main(){
    int N , sum = 0;
    cin >> N;
    for(int i = 3 ; i <= N ; ++i)
	sum = sum + i * (i - 1);
    cout << sum;
    return 0;
}