#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;

int main()
{
	int n;
	int a[102];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
				cout << j+1 << " " << j+2 << "\n";
				swap(a[j],a[j+1]);
			}
		}
	}
}