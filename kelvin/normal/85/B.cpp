#include <stdio.h>
#include <iostream>
#include <queue>
#define MAXN 100060

using namespace std;

int n;
long long arr[4][MAXN];

int num[3];
long long serve[3];

inline int min(int a,int b) { return a<b?a:b; }
inline long long max(long long a,long long b) { return a>b?a:b; }

void help(long long *from,long long *to,int num,long long time) {
	int i;
	long long tp,tb,tf;
	priority_queue<long long> pq;
	for(i=0;i<num;i++)
		pq.push(0);
	for(i=0;i<n;i++) {
		tp=from[i];
		tb=-pq.top();
		pq.pop();
		tf=max(tp,tb)+time;
		to[i]=tf;
		pq.push(-tf);
	}
}

inline long long solve() {
	int i;
	long long sol=0;
	for(i=0;i<3;i++)
		help(arr[i],arr[i+1],num[i],serve[i]);
	for(i=0;i<n;i++)
		sol=max(sol,arr[3][i]-arr[0][i]);
	return sol;
}

int main(void)
{
	int i;
	for(i=0;i<3;i++)
		cin >> num[i];
	for(i=0;i<3;i++)
		cin >> serve[i];
	cin >> n;
	for(i=0;i<n;i++)
		cin >> arr[0][i];
	for(i=0;i<3;i++)
		num[i]=min(num[i],n);
	cout << solve() << endl;
}