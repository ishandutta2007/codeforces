#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

const int MAXN = 2e5 + 7; 
int arr[MAXN] , N , M , K , dir[MAXN];
priority_queue < int , vector < int > , greater < int > > q; 

bool cmp(int a , int b){
	return arr[a] > arr[b];
}

int main(){
	cin >> N >> M >> K;
	for(int i = 1 ; i <= N ; ++i)
		cin >> arr[dir[i] = i];
	sort(dir + 1 , dir + N + 1 , cmp);
	long long sum = 0;
	for(int i = 1 ; i <= M * K ; ++i){
		sum += arr[dir[i]];
		q.push(dir[i]);
	}
	cout << sum << endl;
	for(int i = 1 ; i < K ; ++i){
		for(int j = 1 ; j < M ; ++j)
			q.pop();
		cout << q.top() << ' ';
		q.pop();
	}
	return 0;
}