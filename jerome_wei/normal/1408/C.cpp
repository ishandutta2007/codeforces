#include<bits/stdc++.h>
using namespace std;
typedef double db;
int n,L;
const int N = 1e5+4;
db t1[N], t2[N];
int a[N];

int Main(){
	cin >> n >> L;
	a[0]=0,a[n+1]=L;
	for(int i=1;i<=n;i++)cin >> a[i];
	t1[0]=t2[n+1]=0;
	for(int i=1;i<=n+1;i++){
		t1[i] = t1[i-1] + (db)(a[i]-a[i-1])/(db)i;
	}
	for(int i=n;~i;i--){
		t2[i] = t2[i+1] + (db)(a[i+1] - a[i])/(db)(n+1-i);
	}
	for(int i=0;i<=n;i++){
		// cout << t1[i] << ":" << t1[i+1] << "|" << t2[i] << "|" << t2[i+1] << endl;
		if(t1[i] < t2[i] && t1[i+1] >= t2[i+1]){
			// cout << t1[i] << ":" << t2[i+1] << endl;
			int d1 = i+1,d2 = n-i+1;
			db dist = a[i+1] - a[i];
			if(t1[i] < t2[i+1])swap(t1[i], t2[i+1]), swap(d1, d2);
			dist-=(t1[i]-t2[i+1])*d2;
			printf("%.10lf\n",dist/(db)(n+2) + t1[i]);
			return 0;
		}
	}
	return 0;
}

int main()
{
	int T;cin >> T;
	while(T--){
		Main();
	}
}