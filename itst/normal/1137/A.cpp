#include<iostream>
#include<cstdio>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
//This code is written by Itst
using namespace std;

inline int read(){
    int a = 0;
    char c = getchar();
    bool f = 0;
    while(!isdigit(c)){
	if(c == '-') f = 1;
	c = getchar();
    }
    while(isdigit(c)){
	a = a * 10 + c - 48;
	c = getchar();
    }
    return f ? -a : a;
}

#define PII pair < int , int >
int num[1007][1007] , h[1007][1007] , l[1007][1007] , N , M;

int main(){
    N = read(); M = read();
    for(int i= 1 ; i <= N ; ++i)
	for(int j = 1 ; j <= M ; ++j)
	    num[i][j] = read();
    vector < PII > vec;
    for(int i = 1 ; i <= N ; ++i){
	vec.clear();
	for(int j = 1 ; j <= M ; ++j)
	    vec.push_back(PII(num[i][j] , j));
	sort(vec.begin() , vec.end());
	int pre = 0 , cnt = 0;
	for(auto t : vec){
	    cnt += pre != t.first;
	    h[i][t.second] = cnt;
	    pre = t.first;
	}
	h[i][0] = cnt;
    }
    for(int i = 1 ; i <= M ; ++i){
	vec.clear();
	for(int j = 1 ; j <= N ; ++j)
	    vec.push_back(PII(num[j][i] , j));
	sort(vec.begin() , vec.end());
	int pre = 0 , cnt = 0;
	for(auto t : vec){
	    cnt += pre != t.first;
	    l[t.second][i] = cnt;
	    pre = t.first;
	}
	l[0][i] = cnt;
    }
    for(int i = 1 ; i <= N ; ++i){
	for(int j = 1 ; j <= M ; ++j)
	    cout << max(h[i][0] + max(h[i][j] , l[i][j]) - h[i][j] , l[0][j] + max(h[i][j] , l[i][j]) - l[i][j]) << ' ';
	cout << endl;
    }
    return 0;
}