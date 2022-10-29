#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MAXN = 1e5 + 10;

int main(){
	int n;
	cin>>n;
	int x = 0,y = 0,z;
	for(int i = 1; i <= n; i++){
		scanf("%d", &z);
		x |= z;
	}
	for(int i = 1; i <= n; i++){
		scanf("%d", &z);
		y |= z;
	}
	cout<<x+y<<endl;
	return 0;
}